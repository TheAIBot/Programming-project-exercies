#
# ZDS II Make File - HelloWorld, Debug
#

CC = @C:\PROGRA~2\ZiLOG\ZDSII_~1.3\bin\eZ8cc
ASM = @C:\PROGRA~2\ZiLOG\ZDSII_~1.3\bin\eZ8asm
LINK = @C:\PROGRA~2\ZiLOG\ZDSII_~1.3\bin\eZ8link
LIB = @C:\PROGRA~2\ZiLOG\ZDSII_~1.3\bin\eZ8lib

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
#   -stdinc:"C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std;C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog;C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\Z8Encore_F640X"
#   -strict
#   -usrinc:"M:\Documents\GitHub\Programming-project-exercies\Z8encore\include;C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\Z8encore\include;C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\Z8encore\include"
#   -NOwatch -cpu:Z8F6403
#   -asmsw:" -cpu:Z8F6403 -define:_Z8F6403=1 -define:_Z8ENCORE_640_FAMILY=1 -define:_Z8ENCORE_F640X=1 -define:_MODEL_LARGE=1 -include:C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std;C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog;C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\Z8Encore_F640X -revaa"
CFLAGS = -sw:C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\HelloWorld_Debug.ccsw
# assembler options
#   -debug -define:_Z8F6403=1 -define:_Z8ENCORE_640_FAMILY=1
#   -define:_Z8ENCORE_F640X=1 -define:_MODEL_LARGE=1 -genobj -NOigcase
#   -include:"C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std;C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog;C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\Z8Encore_F640X"
#   -list -NOlistmac -name -pagelen:56 -pagewidth:80 -quiet -sdiopt
#   -warn -NOzmasm -revaa -cpu:Z8F6403
AFLAGS = -sw:C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\HelloWorld_Debug.asmsw

OUTDIR = C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\

Debug: HelloWorld

deltarget: 
	@if exist C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\HelloWorld.lod  \
            del C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\HelloWorld.lod

clean: 
	@if exist C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\HelloWorld.lod  \
            del C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\HelloWorld.lod
	@if exist C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\zsldevinit.obj  \
            del C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\zsldevinit.obj
	@if exist C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\ansi.obj  \
            del C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\ansi.obj
	@if exist C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\ball.obj  \
            del C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\ball.obj
	@if exist C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\boss.obj  \
            del C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\boss.obj
	@if exist C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\bounce.obj  \
            del C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\bounce.obj
	@if exist C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\brick.obj  \
            del C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\brick.obj
	@if exist C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\buttonio.obj  \
            del C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\buttonio.obj
	@if exist C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\clockio.obj  \
            del C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\clockio.obj
	@if exist C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\game.obj  \
            del C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\game.obj
	@if exist C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\joystick.obj  \
            del C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\joystick.obj
	@if exist C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\level.obj  \
            del C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\level.obj
	@if exist C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\powerup.obj  \
            del C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\powerup.obj
	@if exist C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\random.obj  \
            del C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\random.obj
	@if exist C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\readonlymemory.obj  \
            del C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\readonlymemory.obj
	@if exist C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\screenio.obj  \
            del C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\screenio.obj
	@if exist C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\sound.obj  \
            del C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\sound.obj
	@if exist C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\striker.obj  \
            del C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\striker.obj
	@if exist C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\timer.obj  \
            del C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\timer.obj
	@if exist C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\trigonometry.obj  \
            del C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\trigonometry.obj
	@if exist C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\main.obj  \
            del C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\main.obj
	@if exist C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\charset.obj  \
            del C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\charset.obj

rebuildall: clean Debug

relink: deltarget Debug

LIBS = 

OBJS =  \
            C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\zsldevinit.obj  \
            C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\ansi.obj  \
            C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\ball.obj  \
            C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\boss.obj  \
            C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\bounce.obj  \
            C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\brick.obj  \
            C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\buttonio.obj  \
            C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\clockio.obj  \
            C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\game.obj  \
            C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\joystick.obj  \
            C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\level.obj  \
            C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\powerup.obj  \
            C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\random.obj  \
            C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\readonlymemory.obj  \
            C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\screenio.obj  \
            C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\sound.obj  \
            C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\striker.obj  \
            C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\timer.obj  \
            C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\trigonometry.obj  \
            C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\main.obj  \
            C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\charset.obj

HelloWorld: $(OBJS)
	 $(LINK)  @C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\HelloWorld_Debug.linkcmd

C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\zsldevinit.obj :  \
            C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\zsldevinit.asm  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\ez8dev.inc  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\gpio.inc
	 $(ASM)  $(AFLAGS) C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\zsldevinit.asm

C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\ansi.obj :  \
            C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\ansi.c  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDIO.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDIO.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\dmadefs.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\ez8.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\gpio.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\SIO.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h
	 $(CC)  $(CFLAGS) C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\ansi.c

C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\ball.obj :  \
            C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\ball.c  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDIO.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\dmadefs.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\ez8.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\gpio.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\SIO.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h
	 $(CC)  $(CFLAGS) C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\ball.c

C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\boss.obj :  \
            C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\boss.c  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDIO.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\dmadefs.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\ez8.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\gpio.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\SIO.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h
	 $(CC)  $(CFLAGS) C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\boss.c

C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\bounce.obj :  \
            C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\bounce.c  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDIO.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\dmadefs.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\ez8.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\gpio.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\SIO.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h
	 $(CC)  $(CFLAGS) C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\bounce.c

C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\brick.obj :  \
            C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\brick.c  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDIO.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\dmadefs.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\ez8.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\gpio.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\SIO.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h
	 $(CC)  $(CFLAGS) C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\brick.c

C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\buttonio.obj :  \
            C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\buttonio.c  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDIO.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\dmadefs.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\ez8.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\gpio.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\SIO.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h
	 $(CC)  $(CFLAGS) C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\buttonio.c

C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\clockio.obj :  \
            C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\clockio.c  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDIO.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\dmadefs.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\ez8.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\gpio.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\SIO.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h
	 $(CC)  $(CFLAGS) C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\clockio.c

C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\game.obj :  \
            C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\game.c  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDIO.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDIO.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\dmadefs.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\ez8.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\gpio.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\SIO.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h
	 $(CC)  $(CFLAGS) C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\game.c

C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\joystick.obj :  \
            C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\joystick.c  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDIO.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\dmadefs.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\ez8.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\gpio.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\SIO.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h
	 $(CC)  $(CFLAGS) C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\joystick.c

C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\level.obj :  \
            C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\level.c  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDIO.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\dmadefs.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\ez8.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\gpio.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\SIO.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h
	 $(CC)  $(CFLAGS) C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\level.c

C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\powerup.obj :  \
            C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\powerup.c  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDIO.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\dmadefs.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\ez8.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\gpio.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\SIO.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h
	 $(CC)  $(CFLAGS) C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\powerup.c

C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\random.obj :  \
            C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\random.c
	 $(CC)  $(CFLAGS) C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\random.c

C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\readonlymemory.obj :  \
            C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\readonlymemory.c
	 $(CC)  $(CFLAGS) C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\readonlymemory.c

C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\screenio.obj :  \
            C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\screenio.c  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDIO.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\dmadefs.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\ez8.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\gpio.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\SIO.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h
	 $(CC)  $(CFLAGS) C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\screenio.c

C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\sound.obj :  \
            C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\sound.c  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDIO.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\dmadefs.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\ez8.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\gpio.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\SIO.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h
	 $(CC)  $(CFLAGS) C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\sound.c

C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\striker.obj :  \
            C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\striker.c  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDIO.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\dmadefs.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\ez8.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\gpio.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\SIO.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h
	 $(CC)  $(CFLAGS) C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\striker.c

C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\timer.obj :  \
            C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\timer.c  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDIO.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\dmadefs.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\ez8.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\gpio.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\SIO.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h
	 $(CC)  $(CFLAGS) C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\timer.c

C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\trigonometry.obj :  \
            C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\trigonometry.c  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDIO.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\SIO.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h
	 $(CC)  $(CFLAGS) C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\trigonometry.c

C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\main.obj :  \
            C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\ANSIproject\main.c  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDIO.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\dmadefs.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\ez8.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\gpio.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\SIO.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h
	 $(CC)  $(CFLAGS) C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\ANSIproject\main.c

C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\charset.obj :  \
            C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\charset.c  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDIO.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\dmadefs.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\ez8.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\gpio.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\SIO.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h
	 $(CC)  $(CFLAGS) C:\Users\QuantumX\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\charset.c

