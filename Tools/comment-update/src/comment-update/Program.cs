using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using ClangSharp;
using ClangSharp.Interop;
using Dia2Lib;

namespace comment_update
{
    class Program
    {
        static int Main(string[] args)
        {
            if (args.Length < 2)
            {
                Console.WriteLine($"Usage: {Path.GetFileName(Process.GetCurrentProcess().MainModule?.FileName)} <pdb file> <source file 1> [<source file 2> ...]");
				if (Debugger.IsAttached)
					args = new[] { @"..\..\..\..\..\..\Release\MQ2Main.pdb", @"..\..\..\..\..\..\MQ2Main\MQ2Main.cpp" };
				else
					return 1;
			}

			// Get offsets from PDB
			var structs = StructDefinition.ParsePdb(args[0]).ToList();

            // Get location in source files from clang
            List<(string File, uint Line, string Offset)> offsetLocations = new List<(string, uint, string)>();
            foreach (var sourceFile in args.Skip(1))
            {
                var tuHandle = CXTranslationUnit.Parse(CXIndex.Create(), sourceFile, Array.Empty<string>(), Array.Empty<CXUnsavedFile>(), CXTranslationUnit_Flags.CXTranslationUnit_None);
                var tu = TranslationUnit.GetOrCreate(tuHandle).TranslationUnitDecl;
                
                foreach (var ns in tu.CursorChildren.Where(c => c is NamespaceDecl).Cast<NamespaceDecl>())
                    offsetLocations.AddRange(GetOffsetLocations(ns, structs));
            }

            foreach (var fileGroup in offsetLocations.GroupBy(loc => loc.File))
            {
                var lines = File.ReadAllLines(fileGroup.Key);
                foreach (var location in fileGroup)
                {
                    var before = lines[location.Line - 1];
                    var after = Regex.Replace(before, @"^(?<whitespace>\s*)(?<comment>/\*.*?\*/)? ?(?<rest>.*)",
                        $"${{whitespace}}/*0x{location.Offset}*/ ${{rest}}");
                    lines[location.Line - 1] = after;
                }

                File.WriteAllLines(fileGroup.Key, lines);
            }

            return 0;
        }

        private static IEnumerable<(string File, uint Line, string Offset)> GetOffsetLocations(NamespaceDecl ns, IReadOnlyList<StructDefinition> structs)
        {
            foreach (var child in ns.CursorChildren)
            {
                switch (child)
                {
                    case NamespaceDecl childNs:
                        foreach (var offsetLocation in GetOffsetLocations(childNs, structs))
                            yield return offsetLocation;
                        break;
                    case RecordDecl record:
                        foreach (var offsetLocation in GetOffsetLocations(record, structs))
                            yield return offsetLocation;
                        break;
                }
            }
        }

        private static IEnumerable<(string File, uint Line, string Offset)> GetOffsetLocations(RecordDecl record, IReadOnlyList<StructDefinition> structs)
        {
            // Even if we're not updating comments for this type, still need to check nested types
            foreach (var child in record.CursorChildren.Where(c => c is RecordDecl).Cast<RecordDecl>())
                foreach (var offsetLocation in GetOffsetLocations(child, structs))
                    yield return offsetLocation;

            // Custom attributes aren't included in the AST, so search for it manually
            record.Location.GetFileLocation(out var classFile, out var classLine, out _, out _);
            if (!File.ReadAllLines(classFile.ToString())[classLine - 1].Contains("[[offsetcomments]]"))
                yield break;

            var name = GetFullName(record);

            var definition = structs.SingleOrDefault(s => s.Name == name);
            if (definition == null)
            {
                Console.WriteLine($"{name} ({Path.GetFileName(classFile.ToString())}) not found in pdb, skipping");
                yield break;
            }

            Console.WriteLine($"Updating offsets for {name} ({Path.GetFileName(classFile.ToString())})");

            // Format all offsets with enough digits for the largest in the struct
            var digits = definition.Members.Count == 0
                ? 0
                : Math.Max(2, definition.Members.Max(m => m.Offset).ToString("X").Length);
			
			foreach (var field in record.CursorChildren.Where(c => c is FieldDecl).Cast<FieldDecl>())
            {
                field.Location.GetFileLocation(out var fieldFile, out var fieldLine, out _, out _);

                var member = definition.Members.SingleOrDefault(m => m.Name == field.Name);
                if (member == null)
                    Console.WriteLine($"{name}::{field.Name} not found in pdb, skipping");
                else
                    yield return (fieldFile.ToString(), fieldLine, member.Offset.ToString($"X{digits}"));
            }

	        var anonFields = new Stack<CXXRecordDecl>(
		        record.CursorChildren.Where(c => c is CXXRecordDecl field && field.Name == "").Cast<CXXRecordDecl>());

	        while (anonFields.Count > 0)
	        {
		        foreach (var cursor in anonFields.Pop().CursorChildren)
		        {
			        switch (cursor)
			        {
				        case FieldDecl field:
					        field.Location.GetFileLocation(out var fieldFile, out var fieldLine, out _, out _);
					        var member = definition.Members.SingleOrDefault(m => m.Name == field.Name);
					        if (member == null)
						        Console.WriteLine($"{name}::{field.Name} not found in pdb, skipping");
					        else
						        yield return (fieldFile.ToString(), fieldLine, member.Offset.ToString($"X{digits}"));
							break;

						case CXXRecordDecl anonField when anonField.Name == "":
							anonFields.Push(anonField);
							break;
			        }
		        }
	        }
        }

		private static string GetFullName(RecordDecl record)
		{
			// Returns e.g. eqlib::someclass::nestedstruct
			var nsPath = "";
            var parent = record.CursorParent;
            while (parent != null && new[] { CXCursorKind.CXCursor_Namespace, CXCursorKind.CXCursor_ClassDecl, CXCursorKind.CXCursor_StructDecl }.Contains(parent.Kind))
            {
                nsPath = $"{parent}::{nsPath}";
                parent = parent.CursorParent;
            }

            return nsPath == "" ? record.ToString() : $"{nsPath}{record}";
        }
    }

    public class StructDefinition
    {
        public class StructMember
        {
            public string Name { get; }
            public int Offset { get; }
            public uint Size { get; }

            public StructMember(string name, int offset, uint size)
            {
                Name = name;
                Offset = offset;
                Size = size;
            }

            public override string ToString() => Name;
        }

        public string Name { get; private set; }
        public IReadOnlyList<StructMember> Members => _members.AsReadOnly();

        private readonly List<StructMember> _members = new List<StructMember>();

        private StructDefinition()
        {
        }

        public override string ToString() => Name;

        public static IEnumerable<StructDefinition> ParsePdb(string filePath)
        {
            var source = new DiaSource();
            source.loadDataFromPdb(filePath);
            source.openSession(out var session);

            session.globalScope.findChildren(SymTagEnum.SymTagUDT, null, 0, out var enumSymbols);

            var processedSymbols = new HashSet<string>();
            foreach (IDiaSymbol symbol in enumSymbols)
            {
                // It contains two entries for some symbols?
                if (processedSymbols.Contains(symbol.name))
                    continue;
                processedSymbols.Add(symbol.name);

                symbol.findChildren(SymTagEnum.SymTagNull, null, 0, out var members);

                var structDef = new StructDefinition { Name = symbol.name };
                foreach (IDiaSymbol member in members)
                {
                    if ((SymTagEnum)member.symTag == SymTagEnum.SymTagData)
                        structDef._members.Add(new StructMember(member.name, member.offset, member.sizeInUdt));
                }

                yield return structDef;
            }
        }
    }
}
