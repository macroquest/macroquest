DXSDK=..\..\dxsdk81
INTDIR=.

all: testmem.exe

clean:
    del *.obj

testmem.obj: testmem.c ..\mq2main\mq2detourapi.cpp


testmem.exe: testmem.obj orig.obj  orig1.obj orig2.obj orig3.obj orig4.obj
    link $**  /out:testmem.exe /debugtype:cv /pdb:testmem.pdb /debug /libpath:"..\Detours\lib60" user32.lib

.asm.obj:
    ml.exe /c /coff $<

CPP_PROJ=/nologo /MT /W3 /GX /O2 /I "$(DXSDK)\include" /D "_USRDLL" /D "EQLIB_EXPORTS" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "CINTERFACE" /Fp"$(INTDIR)\eqlib.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c  /Zi /Zp1 /TP

.c.obj:
    $(CC) $(CPP_PROJ) $< 
