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
using Newtonsoft.Json;

namespace comment_update
{
    public class ProgramOptions
    {
        public string sourceRoot { get; set; }
        public string[] inputSources { get; set; }
        public string inputSymbols { get; set; }
        public string[] includePaths { get; set; }
        public string[] compilerArguments { get; set; }

        public static ProgramOptions LoadJson(string filename)
        {
            try
            {
                using (StreamReader r = new StreamReader(filename))
                {
                    var json = r.ReadToEnd();
                    var items = JsonConvert.DeserializeObject<ProgramOptions>(json);

                    return items;
                }
            }
            catch (Exception)
            {
                return null;
            }
        }
    }

    class Program
    {
        static int Main(string[] args)
        {
            var currentDir = System.IO.Directory.GetCurrentDirectory();

            // Load settings
            var settingsFile = Path.Combine(currentDir, "comment-update.config");
            var settings = ProgramOptions.LoadJson(settingsFile);
            if (settings == null)
            {
                Console.WriteLine("Failed to load settings");
                return 1;
            }

            var includePaths = new List<string>(settings.includePaths);
            var compilerArguments = new List<string>(settings.compilerArguments);
            var inputSources = new List<string>(settings.inputSources);
            var sourceRoot = Path.Combine(currentDir, settings.sourceRoot);
            var PdbFile = Path.Combine(sourceRoot, settings.inputSymbols);

            bool archIs32bit = false;

            if (args.Length > 0)
            {
                foreach (var item in args)
                {
                    if (item == "-x86")
                    {
                        archIs32bit = true;
                        break;
                    }
                }
            }

            if (archIs32bit)
            {
                Console.WriteLine("Updating comments for x86");
                includePaths.Add("contrib/vcpkg/installed/x86-windows-static/include");
                includePaths.Add("contrib/vcpkg/installed/x86-windows/include");
                compilerArguments.Add("-m32");
            }
            else
            {
                Console.WriteLine("Updating comments for x64");
                includePaths.Add("contrib/vcpkg/installed/x64-windows-static/include");
                includePaths.Add("contrib/vcpkg/installed/x64-windows/include");
                compilerArguments.Add("-m64");
                compilerArguments.Add("-D_WIN64");
            }

            // Get the Pdb
            if (!File.Exists(PdbFile))
            {
                Console.WriteLine("ERROR: PDB file doesn't exist: {0}", PdbFile);
                return 1;
            }

            PdbFile = Path.GetFullPath(new Uri(PdbFile).LocalPath);

            // Get offsets from PDB
            var structs = StructDefinition.ParsePdb(PdbFile).ToList();

            // build the arguments to clang.
            List<string> clangArgs = new List<string>();

            // build include path arguments
            foreach (string arg in includePaths)
            {
                clangArgs.Add("-I" + Path.Combine(sourceRoot, arg));
            }

            // add the rest of the arguments
            clangArgs.AddRange(compilerArguments);

            // Get location in source files from clang
            HashSet<(string File, uint Line, string Offset)> offsetLocations = new HashSet<(string, uint, string)>();
            foreach (var sourceFile in inputSources)
            {
                CXTranslationUnit tuHandle;

                Console.WriteLine("Parsing {0}...", sourceFile);
                var sourceFile2 = Path.Combine(sourceRoot, sourceFile);

                CXErrorCode ec = CXTranslationUnit.TryParse(CXIndex.Create(), sourceFile2, clangArgs.ToArray(),
                    Array.Empty<CXUnsavedFile>(), CXTranslationUnit_Flags.CXTranslationUnit_SkipFunctionBodies, out tuHandle);
                if (ec != CXErrorCode.CXError_Success || tuHandle == null)
                {
                    Console.WriteLine("Failed to parse {0}: {1}", sourceFile, ec.ToString());
                    return 1;
                }

                CXDiagnosticSet diags = tuHandle.DiagnosticSet;
                bool hasError = false;

                if (diags.Count > 0)
                {
                    Console.WriteLine("{0} Diagnostic messages:", diags.Count);
                }

                for (var i = 0u; i < diags.Count; ++i)
                {
                    var diag = diags[i];
                    CXString s = diag.Format(CXDiagnosticDisplayOptions.CXDiagnostic_DisplaySourceLocation
                        | CXDiagnosticDisplayOptions.CXDiagnostic_DisplayOption);
                    Console.WriteLine("{0}", s.ToString());

                    if (diag.Severity == CXDiagnosticSeverity.CXDiagnostic_Error
                        || diag.Severity == CXDiagnosticSeverity.CXDiagnostic_Fatal)
                    {
                        hasError = true;
                    }
                }

                if (hasError)
                {
                    Console.WriteLine("One or more errors occurred while parsing {0}", sourceFile);
                    return 1;
                }

                var tu = TranslationUnit.GetOrCreate(tuHandle).TranslationUnitDecl;
                if (tu == null)
                {
                    Console.WriteLine("Failed to create translation unit for {0}", sourceFile);
                    return 1;
                }

                var children = tu.CursorChildren;

                foreach (var ns in children.Where(c => c is NamespaceDecl).Cast<NamespaceDecl>())
                    offsetLocations.UnionWith(GetOffsetLocations(ns, structs));
            }

            foreach (var fileGroup in offsetLocations.GroupBy(loc => loc.File))
            {
                Console.WriteLine("Updating {0}...", Path.GetFullPath(fileGroup.Key));
                var lines = File.ReadAllLines(fileGroup.Key);
                foreach (var location in fileGroup)
                {
                    var before = lines[location.Line - 1];
                    var after = Regex.Replace(before, @"^(?<whitespace>\s*)(?<comment>/\*.*?\*/)? ?(?<rest>.*)",
                        $"${{whitespace}}/*0x{location.Offset}*/ ${{rest}}");
                    after = after.TrimEnd(null);
                    lines[location.Line - 1] = after;
                }

                File.WriteAllLines(fileGroup.Key, lines);
            }

            Console.WriteLine("Done!");

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
            var name = GetFullName(record);

            // Even if we're not updating comments for this type, still need to check nested types
            foreach (var child in record.CursorChildren.Where(c => c is RecordDecl).Cast<RecordDecl>())
                foreach (var offsetLocation in GetOffsetLocations(child, structs))
                    yield return offsetLocation;

            // Custom attributes aren't included in the AST, so search for it manually
            record.Location.GetFileLocation(out var classFile, out var classLine, out _, out _);
            var match = Regex.Match(File.ReadAllLines(classFile.ToString())[classLine - 1],
                @"\[\[offsetcomments(?:\((?<base>-?0x[0-9a-fA-F]+|\d+)\))?\]\]");

            if (!match.Success)
                yield break;

            var baseOffset = 0;
            if (match.Groups["base"].Success)
            {
                var baseStr = match.Groups["base"].Captures[0].Value;
                if (!int.TryParse(baseStr, out baseOffset))
                    baseOffset = Convert.ToInt32(baseStr, 16);
            }

            var definition = structs.SingleOrDefault(s => s.Name == name);
            if (definition == null)
            {
                Console.WriteLine($"{name} ({Path.GetFileName(classFile.ToString())}) not found in pdb, skipping");
                yield break;
            }

            Console.WriteLine($"Updating offsets for {name} ({Path.GetFileName(classFile.ToString())})");

            var locations = new List<(FieldDecl Field, string File, uint Line, int Offset)>();
            var members = new List<FieldDecl>();

            // Add any fields
            members.AddRange(record.CursorChildren.Where(c => c is FieldDecl).Cast<FieldDecl>());

            // And any fields within anonymous types
            var anonFields = new Stack<CXXRecordDecl>(
                record.CursorChildren.Where(c => c is CXXRecordDecl field && field.Name == "").Cast<CXXRecordDecl>());

            while (anonFields.Count > 0)
            {
                foreach (var cursor in anonFields.Pop().CursorChildren)
                {
                    switch (cursor)
                    {
                        case FieldDecl field:
                            members.Add(field);
                            break;

                        case CXXRecordDecl anonField when anonField.Name == "":
                            anonFields.Push(anonField);
                            break;
                    }
                }
            }

            foreach (var field in members)
            {
                field.Location.GetFileLocation(out var fieldFile, out var fieldLine, out _, out _);

                var member = definition.Members.SingleOrDefault(m => m.Name == field.Name);
                if (member == null)
                    Console.WriteLine($"{name}::{field.Name} not found in pdb, skipping");
                else
                {
                    locations.Add((field, fieldFile.ToString(), fieldLine, member.Offset + baseOffset));
                }
            }

            if (locations.Count == 0)
                yield break;

            // Get the struct size. Can't find it in the PDB, so using the largest offset + that field's size from clang, aligned to 4 bytes
            var lastMember = locations.OrderBy(loc => loc.Offset).ThenBy(loc => loc.Line).Last();
            var size = lastMember.Offset + lastMember.Field.Type.Handle.SizeOf;
            size = (long)(Math.Ceiling((double)size / 4) * 4);

            // Format all offsets with enough digits for the size
            var digits = Math.Max(2, size.ToString("X").Length);

            // Return locations for all members
            foreach (var location in locations)
                yield return (Path.GetFullPath(location.File), location.Line, location.Offset.ToString($"x{digits}"));

            // And one for the size.
            // If the last member is in the same source file as the struct itself, it just goes on the following line
            if (lastMember.File == classFile.ToString())
            {
                // It could be in an anonymous union/struct, in which case we want it after that rather than after the member
                Cursor actualLastMember = lastMember.Field;
                while (actualLastMember.SemanticParentCursor != record)
                    actualLastMember = actualLastMember.SemanticParentCursor;

                actualLastMember.Extent.End.GetFileLocation(out var file, out var line, out _, out _);

                yield return (Path.GetFullPath(file.ToString()), line + 1, size.ToString($"x{digits}"));
                yield break;
            }

            // Otherwise, it goes on the line before the first non-field declaration after all the field declarations
            var children = record.CursorChildren.Where(c =>
            {
                c.Location.GetFileLocation(out var file, out _, out _, out _);
                return file.ToString() == classFile.ToString();
            }).ToList();

            for (var i = children.Count - 1; i >= 0; i--)
            {
                if (children[i] is FieldDecl || (children[i] is CXXRecordDecl anonField && anonField.Name == ""))
                {
                    if (i != (children.Count - 1))
                    {
                        children[i + 1].Location.GetFileLocation(out var file, out var line, out _, out _);
                        yield return (Path.GetFullPath(file.ToString()), line - 1, size.ToString($"x{digits}"));
                        yield break;
                    }
                }
            }

            // If we still couldn't place it, throw it on the last line of the class
            record.Extent.End.GetFileLocation(out var lastLineFile, out var lastLine, out _, out _);
            yield return (Path.GetFullPath(lastLineFile.ToString()), lastLine, size.ToString($"x{digits}"));
        }

        private static string GetFullName(RecordDecl record)
        {
            // Returns e.g. eqlib::someclass::nestedstruct
            var nsPath = "";
            var parent = record.SemanticParentCursor;
            while (parent != null && new[] { CXCursorKind.CXCursor_Namespace, CXCursorKind.CXCursor_ClassDecl, CXCursorKind.CXCursor_StructDecl }.Contains(parent.CursorKind))
            {
                nsPath = $"{parent}::{nsPath}";
                parent = parent.SemanticParentCursor;
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
                if (symbol == null)
                    continue;

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
