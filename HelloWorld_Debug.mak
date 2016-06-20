#
# ZDS II Make File - HelloWorld, Debug
#

CC = @D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\bin\eZ8cc
ASM = @D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\bin\eZ8asm
LINK = @D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\bin\eZ8link
LIB = @D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\bin\eZ8lib

# compiler options
#   -alias -asm -bitfieldsize:32 -charsize:8 -const:RAM -debug
#   -define:_Z8F6403 -define:_Z8ENCORE_640_FAMILY
#   -define:_Z8ENCORE_F640X -define:_MODEL_LARGE -define:_SIMULATE
#   -doublesize:32 -NOexpmac -floatsize:32 -NOfplib -genprintf
#   -NOglobalcopy -NOglobalcse -NOglobalfold -intrinsic -intsize:16
#   -intsrc -NOjmpopt -NOkeepasm -NOkeeplst -NOlist -NOlistinc
#   -localcopy -localcse -localfold -longsize:32 -NOloopopt -maxerrs:50
#   -model:L -NOoptlink -optsize -peephole -NOpromote -quiet -regvar
#   -revaa -NOsdiopt -shortsize:16
#   -stdinc:"D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\std;D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog;D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\Z8Encore_F640X"
#   -strict
#   -usrinc:"M:\Documents\GitHub\Programming-project-exercies\Z8encore\include;C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\Z8encore\include;C:\Users\s153498\Desktop\Microprocessorprogrammer\HelloWorld\Programming-project-exercies\Z8encore\include"
#   -NOwatch -cpu:Z8F6403
#   -asmsw:" -cpu:Z8F6403 -define:_Z8F6403=1 -define:_Z8ENCORE_640_FAMILY=1 -define:_Z8ENCORE_F640X=1 -define:_MODEL_LARGE=1 -define:_SIMULATE=1 -include:D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\std;D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog;D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\Z8Encore_F640X -revaa"
CFLAGS = -sw:C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\HelloWorld_Debug.ccsw
# assembler options
#   -debug -define:_Z8F6403=1 -define:_Z8ENCORE_640_FAMILY=1
#   -define:_Z8ENCORE_F640X=1 -define:_MODEL_LARGE=1 -define:_SIMULATE=1
#   -genobj -NOigcase
#   -include:"D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\std;D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog;D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\Z8Encore_F640X"
#   -list -NOlistmac -name -pagelen:56 -pagewidth:80 -quiet -sdiopt
#   -warn -NOzmasm -revaa -cpu:Z8F6403
AFLAGS = -sw:C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\HelloWorld_Debug.asmsw

OUTDIR = C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\

Debug: HelloWorld

deltarget: 
	@if exist C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\HelloWorld.lod  \
            del C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\HelloWorld.lod

clean: 
	@if exist C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\HelloWorld.lod  \
            del C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\HelloWorld.lod
	@if exist C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\zsldevinit.obj  \
            del C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\zsldevinit.obj
	@if exist C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\main.obj  \
            del C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\main.obj
	@if exist C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\ansi.obj  \
            del C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\ansi.obj
	@if exist C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\buttonio.obj  \
            del C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\buttonio.obj
	@if exist C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\clockio.obj  \
            del C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\clockio.obj
	@if exist C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\ball.obj  \
            del C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\ball.obj
	@if exist C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\boss.obj  \
            del C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\boss.obj
	@if exist C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\brick.obj  \
            del C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\brick.obj
	@if exist C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\game.obj  \
            del C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\game.obj
	@if exist C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\level.obj  \
            del C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\level.obj
	@if exist C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\powerup.obj  \
            del C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\powerup.obj
	@if exist C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\striker.obj  \
            del C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\striker.obj
	@if exist C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\timer.obj  \
            del C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\timer.obj
	@if exist C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\random.obj  \
            del C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\random.obj
	@if exist C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\joystick.obj  \
            del C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\joystick.obj
	@if exist C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\bounce.obj  \
            del C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\bounce.obj
	@if exist C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\trigonometry.obj  \
            del C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\trigonometry.obj
	@if exist C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\screenio.obj  \
            del C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\screenio.obj
	@if exist C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\sound.obj  \
            del C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\sound.obj
	@if exist C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\readonlymemory.obj  \
            del C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\readonlymemory.obj
	@if exist C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\tests.obj  \
            del C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\tests.obj
	@if exist C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\charset.obj  \
            del C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\charset.obj

rebuildall: clean Debug

relink: deltarget Debug

LIBS = 

OBJS =  \
            C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\zsldevinit.obj  \
            C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\main.obj  \
            C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\ansi.obj  \
            C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\buttonio.obj  \
            C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\clockio.obj  \
            C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\ball.obj  \
            C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\boss.obj  \
            C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\brick.obj  \
            C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\game.obj  \
            C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\level.obj  \
            C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\powerup.obj  \
            C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\striker.obj  \
            C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\timer.obj  \
            C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\random.obj  \
            C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\joystick.obj  \
            C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\bounce.obj  \
            C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\trigonometry.obj  \
            C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\screenio.obj  \
            C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\sound.obj  \
            C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\readonlymemory.obj  \
            C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\tests.obj  \
            C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\charset.obj

HelloWorld: $(OBJS)
	 $(LINK)  @C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\HelloWorld_Debug.linkcmd

C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\zsldevinit.obj :  \
            C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\zsldevinit.asm  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\ez8dev.inc  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\gpio.inc
	 $(ASM)  $(AFLAGS) C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\zsldevinit.asm

C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\main.obj :  \
            C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\Z8encore\ANSIproject\main.c  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\ansi.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\ball.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\boss.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\brick.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\buttonio.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\clockio.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\game.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\joystick.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\sound.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\striker.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\tests.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\timer.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\std\format.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\std\stdarg.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\std\stdio.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\defines.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\dmadefs.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\eZ8.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\gpio.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\sio.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\uart.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\uartdefs.h
	 $(CC)  $(CFLAGS) C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\Z8encore\ANSIproject\main.c

C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\ansi.obj :  \
            C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\ansi.c  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\ansi.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\TRIGON~1.H  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\std\format.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\std\stdarg.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\std\stdio.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\defines.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\dmadefs.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\eZ8.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\gpio.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\sio.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\uart.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\uartdefs.h
	 $(CC)  $(CFLAGS) C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\ansi.c

C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\buttonio.obj :  \
            C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\buttonio.c  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\buttonio.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\clockio.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\std\format.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\std\stdarg.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\std\stdio.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\defines.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\dmadefs.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\eZ8.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\gpio.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\sio.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\uart.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\uartdefs.h
	 $(CC)  $(CFLAGS) C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\buttonio.c

C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\clockio.obj :  \
            C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\clockio.c  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\clockio.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\std\format.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\std\stdarg.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\std\stdio.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\defines.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\dmadefs.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\eZ8.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\gpio.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\sio.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\uart.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\uartdefs.h
	 $(CC)  $(CFLAGS) C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\clockio.c

C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\ball.obj :  \
            C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\ball.c  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\ansi.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\ball.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\boss.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\bounce.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\brick.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\clockio.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\FIXEDM~1.H  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\game.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\sound.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\striker.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\timer.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\TRIGON~1.H  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\std\format.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\std\stdarg.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\std\stdio.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\defines.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\dmadefs.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\eZ8.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\gpio.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\sio.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\uart.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\uartdefs.h
	 $(CC)  $(CFLAGS) C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\ball.c

C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\boss.obj :  \
            C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\boss.c  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\ansi.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\ball.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\boss.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\brick.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\clockio.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\color.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\FIXEDM~1.H  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\game.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\random.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\striker.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\timer.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\std\format.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\std\stdarg.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\std\stdio.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\defines.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\dmadefs.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\eZ8.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\gpio.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\sio.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\uart.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\uartdefs.h
	 $(CC)  $(CFLAGS) C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\boss.c

C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\brick.obj :  \
            C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\brick.c  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\ansi.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\ball.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\boss.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\bounce.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\brick.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\color.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\FIXEDM~1.H  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\game.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\sound.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\striker.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\timer.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\std\format.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\std\stdarg.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\std\stdio.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\defines.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\dmadefs.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\eZ8.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\gpio.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\sio.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\uart.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\uartdefs.h
	 $(CC)  $(CFLAGS) C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\brick.c

C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\game.obj :  \
            C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\game.c  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\SuperIO.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\ansi.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\ball.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\boss.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\brick.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\buttonio.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\clockio.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\color.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\game.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\joystick.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\level.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\powerup.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\random.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\screenio.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\sound.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\striker.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\timer.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\TRIGON~1.H  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\std\format.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\std\stdarg.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\std\stdio.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\defines.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\dmadefs.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\eZ8.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\gpio.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\sio.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\uart.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\uartdefs.h
	 $(CC)  $(CFLAGS) C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\game.c

C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\level.obj :  \
            C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\level.c  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\ansi.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\ball.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\boss.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\brick.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\FIXEDM~1.H  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\game.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\level.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\powerup.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\striker.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\timer.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\std\format.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\std\stdarg.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\std\stdio.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\defines.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\dmadefs.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\eZ8.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\gpio.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\sio.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\uart.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\uartdefs.h
	 $(CC)  $(CFLAGS) C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\level.c

C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\powerup.obj :  \
            C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\powerup.c  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\ansi.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\powerup.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\std\format.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\std\stdarg.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\std\stdio.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\defines.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\dmadefs.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\eZ8.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\gpio.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\sio.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\uart.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\uartdefs.h
	 $(CC)  $(CFLAGS) C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\powerup.c

C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\striker.obj :  \
            C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\striker.c  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\ansi.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\ball.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\color.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\FIXEDM~1.H  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\sound.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\striker.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\TRIGON~1.H  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\std\format.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\std\stdarg.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\std\stdio.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\defines.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\dmadefs.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\eZ8.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\gpio.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\sio.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\uart.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\uartdefs.h
	 $(CC)  $(CFLAGS) C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\striker.c

C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\timer.obj :  \
            C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\timer.c  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\clockio.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\timer.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\std\format.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\std\stdarg.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\std\stdio.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\defines.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\dmadefs.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\eZ8.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\gpio.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\sio.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\uart.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\uartdefs.h
	 $(CC)  $(CFLAGS) C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\timer.c

C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\random.obj :  \
            C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\random.c  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\clockio.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\random.h
	 $(CC)  $(CFLAGS) C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\random.c

C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\joystick.obj :  \
            C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\joystick.c  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\clockio.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\joystick.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\std\format.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\std\stdarg.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\std\stdio.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\defines.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\dmadefs.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\eZ8.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\gpio.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\sio.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\uart.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\uartdefs.h
	 $(CC)  $(CFLAGS) C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\joystick.c

C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\bounce.obj :  \
            C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\bounce.c  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\bounce.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\std\format.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\std\stdarg.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\std\stdio.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\defines.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\dmadefs.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\eZ8.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\gpio.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\sio.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\uart.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\uartdefs.h
	 $(CC)  $(CFLAGS) C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\bounce.c

C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\trigonometry.obj :  \
            C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\trigonometry.c  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\TRIGON~1.H  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\std\format.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\std\stdarg.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\std\stdio.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\defines.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\sio.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\uart.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\uartdefs.h
	 $(CC)  $(CFLAGS) C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\trigonometry.c

C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\screenio.obj :  \
            C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\screenio.c  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\charset.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\clockio.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\std\format.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\std\stdarg.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\std\stdio.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\defines.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\dmadefs.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\eZ8.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\gpio.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\sio.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\uart.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\uartdefs.h
	 $(CC)  $(CFLAGS) C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\screenio.c

C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\sound.obj :  \
            C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\sound.c  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\std\format.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\std\stdarg.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\std\stdio.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\defines.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\dmadefs.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\eZ8.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\gpio.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\sio.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\uart.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\uartdefs.h
	 $(CC)  $(CFLAGS) C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\sound.c

C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\readonlymemory.obj :  \
            C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\readonlymemory.c
	 $(CC)  $(CFLAGS) C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\readonlymemory.c

C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\tests.obj :  \
            C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\tests.c  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\FIXEDM~1.H  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\tests.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\TRIGON~1.H  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\std\format.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\std\stdarg.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\std\stdio.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\defines.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\dmadefs.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\eZ8.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\gpio.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\sio.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\uart.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\uartdefs.h
	 $(CC)  $(CFLAGS) C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\tests.c

C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\charset.obj :  \
            C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\charset.c  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\ansi.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\charset.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\std\format.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\std\stdarg.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\std\stdio.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\defines.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\dmadefs.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\eZ8.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\gpio.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\sio.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\uart.h  \
            D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore493\include\zilog\uartdefs.h
	 $(CC)  $(CFLAGS) C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\charset.c

