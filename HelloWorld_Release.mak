#
# ZDS II Make File - HelloWorld, Release
#

CC = @c:\PROGRA~2\ZiLOG\ZDSII_~1.3\bin\eZ8cc
ASM = @c:\PROGRA~2\ZiLOG\ZDSII_~1.3\bin\eZ8asm
LINK = @c:\PROGRA~2\ZiLOG\ZDSII_~1.3\bin\eZ8link
LIB = @c:\PROGRA~2\ZiLOG\ZDSII_~1.3\bin\eZ8lib

# compiler options
#   -alias -asm -bitfieldsize:32 -charsize:8 -const:RAM -NOdebug
#   -define:_Z8F6403 -define:_Z8ENCORE_640_FAMILY
#   -define:_Z8ENCORE_F640X -define:_MODEL_LARGE -doublesize:32
#   -NOexpmac -floatsize:32 -NOfplib -genprintf -globalcopy -globalcse
#   -globalfold -intrinsic -intsize:16 -intsrc -jmpopt -NOkeepasm
#   -NOkeeplst -NOlist -NOlistinc -localcopy -localcse -localfold
#   -longsize:32 -loopopt -maxerrs:50 -model:L -NOoptlink -optsize
#   -peephole -NOpromote -quiet -regvar -revaa -sdiopt -shortsize:16
#   -stdinc:"c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std;c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog;c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\Z8Encore_F640X"
#   -strict
#   -usrinc:"C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\Z8encore\include;C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\Z8encore\include"
#   -NOwatch -cpu:Z8F6403
#   -asmsw:" -cpu:Z8F6403 -define:_Z8F6403=1 -define:_Z8ENCORE_640_FAMILY=1 -define:_Z8ENCORE_F640X=1 -define:_MODEL_LARGE=1 -include:c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std;c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog;c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\Z8Encore_F640X -revaa"
CFLAGS = -sw:C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\HelloWorld_Release.ccsw
# assembler options
#   -NOdebug -define:_Z8F6403=1 -define:_Z8ENCORE_640_FAMILY=1
#   -define:_Z8ENCORE_F640X=1 -define:_MODEL_LARGE=1 -genobj -NOigcase
#   -include:"c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std;c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog;c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\Z8Encore_F640X"
#   -list -NOlistmac -name -pagelen:56 -pagewidth:80 -quiet -sdiopt
#   -warn -NOzmasm -revaa -cpu:Z8F6403
AFLAGS = -sw:C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\HelloWorld_Release.asmsw

OUTDIR = C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\

Release: HelloWorld

deltarget: 
	@if exist C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\HelloWorld.lod  \
            del C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\HelloWorld.lod
	@if exist C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\HelloWorld.hex  \
            del C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\HelloWorld.hex

clean: 
	@if exist C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\HelloWorld.lod  \
            del C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\HelloWorld.lod
	@if exist C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\HelloWorld.hex  \
            del C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\HelloWorld.hex
	@if exist C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\zsldevinit.obj  \
            del C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\zsldevinit.obj
	@if exist C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\main.obj  \
            del C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\main.obj
	@if exist C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\ansi.obj  \
            del C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\ansi.obj
	@if exist C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\buttonio.obj  \
            del C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\buttonio.obj
	@if exist C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\clockio.obj  \
            del C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\clockio.obj
	@if exist C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\ball.obj  \
            del C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\ball.obj
	@if exist C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\boss.obj  \
            del C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\boss.obj
	@if exist C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\brick.obj  \
            del C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\brick.obj
	@if exist C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\game.obj  \
            del C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\game.obj
	@if exist C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\level.obj  \
            del C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\level.obj
	@if exist C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\powerup.obj  \
            del C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\powerup.obj
	@if exist C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\striker.obj  \
            del C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\striker.obj
	@if exist C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\timer.obj  \
            del C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\timer.obj
	@if exist C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\random.obj  \
            del C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\random.obj
	@if exist C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\joystick.obj  \
            del C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\joystick.obj
	@if exist C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\bounce.obj  \
            del C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\bounce.obj
	@if exist C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\trigonometry.obj  \
            del C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\trigonometry.obj
	@if exist C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\screenio.obj  \
            del C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\screenio.obj
	@if exist C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\sound.obj  \
            del C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\sound.obj
	@if exist C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\readonlymemory.obj  \
            del C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\readonlymemory.obj

rebuildall: clean Release

relink: deltarget Release

LIBS = 

OBJS =  \
            C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\zsldevinit.obj  \
            C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\main.obj  \
            C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\ansi.obj  \
            C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\buttonio.obj  \
            C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\clockio.obj  \
            C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\ball.obj  \
            C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\boss.obj  \
            C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\brick.obj  \
            C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\game.obj  \
            C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\level.obj  \
            C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\powerup.obj  \
            C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\striker.obj  \
            C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\timer.obj  \
            C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\random.obj  \
            C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\joystick.obj  \
            C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\bounce.obj  \
            C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\trigonometry.obj  \
            C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\screenio.obj  \
            C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\sound.obj  \
            C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\readonlymemory.obj

HelloWorld: $(OBJS)
	 $(LINK)  @C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\HelloWorld_Release.linkcmd

C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\zsldevinit.obj :  \
            C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\zsldevinit.asm  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\ez8dev.inc  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\gpio.inc
	 $(ASM)  $(AFLAGS) C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\zsldevinit.asm

C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\main.obj :  \
            C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\Z8encore\ANSIproject\main.c  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\ansi.h  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\ball.h  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\boss.h  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\brick.h  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\buttonio.h  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\clockio.h  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\game.h  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\joystick.h  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\sound.h  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\striker.h  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\timer.h  \
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
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\ansi.h  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\TRIGON~1.H  \
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

C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\buttonio.obj :  \
            C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\Z8encore\include\src\buttonio.c  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\buttonio.h  \
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

C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\ball.obj :  \
            C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\Z8encore\include\src\ball.c  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\ansi.h  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\ball.h  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\bounce.h  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\clockio.h  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\FIXEDM~1.H  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\sound.h  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\striker.h  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\TRIGON~1.H  \
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
	 $(CC)  $(CFLAGS) C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\Z8encore\include\src\ball.c

C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\boss.obj :  \
            C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\Z8encore\include\src\boss.c  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\ansi.h  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\ball.h  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\boss.h  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\brick.h  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\clockio.h  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\color.h  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\FIXEDM~1.H  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\random.h  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\striker.h  \
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
	 $(CC)  $(CFLAGS) C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\Z8encore\include\src\boss.c

C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\brick.obj :  \
            C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\Z8encore\include\src\brick.c  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\ansi.h  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\ball.h  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\bounce.h  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\brick.h  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\color.h  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\FIXEDM~1.H  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\sound.h  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\striker.h  \
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
	 $(CC)  $(CFLAGS) C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\Z8encore\include\src\brick.c

C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\game.obj :  \
            C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\Z8encore\include\src\game.c  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\SuperIO.h  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\ansi.h  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\ball.h  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\boss.h  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\brick.h  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\buttonio.h  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\clockio.h  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\color.h  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\game.h  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\joystick.h  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\level.h  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\powerup.h  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\random.h  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\screenio.h  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\sound.h  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\striker.h  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\timer.h  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\TRIGON~1.H  \
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
	 $(CC)  $(CFLAGS) C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\Z8encore\include\src\game.c

C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\level.obj :  \
            C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\Z8encore\include\src\level.c  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\ansi.h  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\ball.h  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\boss.h  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\brick.h  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\FIXEDM~1.H  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\game.h  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\level.h  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\powerup.h  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\striker.h  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\timer.h  \
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
	 $(CC)  $(CFLAGS) C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\Z8encore\include\src\level.c

C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\powerup.obj :  \
            C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\Z8encore\include\src\powerup.c  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\ansi.h  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\powerup.h  \
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
	 $(CC)  $(CFLAGS) C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\Z8encore\include\src\powerup.c

C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\striker.obj :  \
            C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\Z8encore\include\src\striker.c  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\ansi.h  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\ball.h  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\color.h  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\FIXEDM~1.H  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\sound.h  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\striker.h  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\TRIGON~1.H  \
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
	 $(CC)  $(CFLAGS) C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\Z8encore\include\src\striker.c

C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\timer.obj :  \
            C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\Z8encore\include\src\timer.c  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\clockio.h  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\timer.h  \
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
	 $(CC)  $(CFLAGS) C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\Z8encore\include\src\timer.c

C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\random.obj :  \
            C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\Z8encore\include\src\random.c  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\clockio.h  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\random.h
	 $(CC)  $(CFLAGS) C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\Z8encore\include\src\random.c

C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\joystick.obj :  \
            C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\Z8encore\include\src\joystick.c  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\clockio.h  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\joystick.h  \
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
	 $(CC)  $(CFLAGS) C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\Z8encore\include\src\joystick.c

C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\bounce.obj :  \
            C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\Z8encore\include\src\bounce.c  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\bounce.h  \
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
	 $(CC)  $(CFLAGS) C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\Z8encore\include\src\bounce.c

C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\trigonometry.obj :  \
            C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\Z8encore\include\src\trigonometry.c  \
            C:\Users\s153498\Desktop\MICROP~1\HELLOW~1\PROGRA~1\Z8encore\include\TRIGON~1.H  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDIO.H  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\SIO.H  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h
	 $(CC)  $(CFLAGS) C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\Z8encore\include\src\trigonometry.c

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

C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\sound.obj :  \
            C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\Z8encore\include\src\sound.c  \
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
	 $(CC)  $(CFLAGS) C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\Z8encore\include\src\sound.c

C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\readonlymemory.obj :  \
            C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\Z8encore\include\src\readonlymemory.c
	 $(CC)  $(CFLAGS) C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\Z8encore\include\src\readonlymemory.c

