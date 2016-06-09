#
# ZDS II Make File - HelloWorld, Debug
#

CC = @c:\PROGRA~2\ZiLOG\ZDSII_~1.3\bin\eZ8cc
ASM = @c:\PROGRA~2\ZiLOG\ZDSII_~1.3\bin\eZ8asm
LINK = @c:\PROGRA~2\ZiLOG\ZDSII_~1.3\bin\eZ8link
LIB = @c:\PROGRA~2\ZiLOG\ZDSII_~1.3\bin\eZ8lib

# compiler options
#   -alias -asm -bitfieldsize:32 -charsize:8 -const:RAM -debug
#   -define:_Z8F6403 -define:_Z8ENCORE_640_FAMILY
#   -define:_Z8ENCORE_F640X -define:_MODEL_LARGE -doublesize:32
#   -NOexpmac -floatsize:32 -NOfplib -genprintf -NOglobalcopy
#   -NOglobalcse -NOglobalfold -intrinsic -intsize:16 -intsrc -NOjmpopt
#   -NOkeepasm -NOkeeplst -NOlist -NOlistinc -localcopy -localcse
#   -localfold -longsize:32 -NOloopopt -maxerrs:50 -model:L -NOoptlink
#   -optsize -peephole -NOpromote -quiet -regvar -revaa -NOsdiopt
#   -shortsize:16
#   -stdinc:"c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std;c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog;c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\Z8Encore_F640X"
#   -strict
#   -usrinc:"M:\Documents\GitHub\Programming-project-exercies\Z8encore\include;C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\Z8encore\include;C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\Z8encore\include"
#   -NOwatch -cpu:Z8F6403
#   -asmsw:" -cpu:Z8F6403 -define:_Z8F6403=1 -define:_Z8ENCORE_640_FAMILY=1 -define:_Z8ENCORE_F640X=1 -define:_MODEL_LARGE=1 -include:c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std;c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog;c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\Z8Encore_F640X -revaa"
CFLAGS = -sw:C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\HelloWorld_Debug.ccsw
# assembler options
#   -debug -define:_Z8F6403=1 -define:_Z8ENCORE_640_FAMILY=1
#   -define:_Z8ENCORE_F640X=1 -define:_MODEL_LARGE=1 -genobj -NOigcase
#   -include:"c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std;c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog;c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\Z8Encore_F640X"
#   -list -NOlistmac -name -pagelen:56 -pagewidth:80 -quiet -sdiopt
#   -warn -NOzmasm -revaa -cpu:Z8F6403
AFLAGS = -sw:C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\HelloWorld_Debug.asmsw

OUTDIR = C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\

Debug: HelloWorld

deltarget: 
	@if exist C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\HelloWorld.lod  \
            del C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\HelloWorld.lod

clean: 
	@if exist C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\HelloWorld.lod  \
            del C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\HelloWorld.lod
	@if exist C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\zsldevinit.obj  \
            del C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\zsldevinit.obj
	@if exist C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\main.obj  \
            del C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\main.obj
	@if exist C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\ansi.obj  \
            del C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\ansi.obj
	@if exist C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\SineLUT.obj  \
            del C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\SineLUT.obj
	@if exist C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\screenio.obj  \
            del C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\screenio.obj
	@if exist C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\buttonio.obj  \
            del C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\buttonio.obj
	@if exist C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\clockio.obj  \
            del C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\clockio.obj

rebuildall: clean Debug

relink: deltarget Debug

LIBS = 

OBJS =  \
            C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\zsldevinit.obj  \
            C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\main.obj  \
            C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\ansi.obj  \
            C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\SineLUT.obj  \
            C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\screenio.obj  \
            C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\buttonio.obj  \
            C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\clockio.obj

HelloWorld: $(OBJS)
	 $(LINK)  @C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\HelloWorld_Debug.linkcmd

C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\zsldevinit.obj :  \
            C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\zsldevinit.asm  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\ez8dev.inc  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\gpio.inc
	 $(ASM)  $(AFLAGS) C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\zsldevinit.asm

C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\main.obj :  \
            C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\Z8encore\ANSIproject\main.c  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\SineLUT.h  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\SuperIO.h  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\ansi.h  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\buttonio.h  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\screenio.h  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDIO.H  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\dmadefs.h  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\ez8.h  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\gpio.h  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\SIO.H  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h
	 $(CC)  $(CFLAGS) C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\Z8encore\ANSIproject\main.c

C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\ansi.obj :  \
            C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\Z8encore\include\src\ansi.c  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDIO.H  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDIO.H  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\dmadefs.h  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\ez8.h  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\gpio.h  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\SIO.H  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h
	 $(CC)  $(CFLAGS) C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\Z8encore\include\src\ansi.c

C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\SineLUT.obj :  \
            C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\Z8encore\include\src\SineLUT.c  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDIO.H  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\SIO.H  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h
	 $(CC)  $(CFLAGS) C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\Z8encore\include\src\SineLUT.c

C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\screenio.obj :  \
            C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\Z8encore\include\src\screenio.c  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\charset.h  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\clockio.h  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDIO.H  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\dmadefs.h  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\ez8.h  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\gpio.h  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\SIO.H  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h
	 $(CC)  $(CFLAGS) C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\Z8encore\include\src\screenio.c

C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\buttonio.obj :  \
            C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\Z8encore\include\src\buttonio.c  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDIO.H  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\dmadefs.h  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\ez8.h  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\gpio.h  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\SIO.H  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h
	 $(CC)  $(CFLAGS) C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\Z8encore\include\src\buttonio.c

C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\clockio.obj :  \
            C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\Z8encore\include\src\clockio.c  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\clockio.h  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDIO.H  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\dmadefs.h  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\ez8.h  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\gpio.h  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\SIO.H  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h
	 $(CC)  $(CFLAGS) C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\Z8encore\include\src\clockio.c

