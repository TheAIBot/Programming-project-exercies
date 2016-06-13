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
CFLAGS = -sw:M:\Documents\GitHub\Programming-project-exercies\HelloWorld_Debug.ccsw
# assembler options
#   -debug -define:_Z8F6403=1 -define:_Z8ENCORE_640_FAMILY=1
#   -define:_Z8ENCORE_F640X=1 -define:_MODEL_LARGE=1 -genobj -NOigcase
#   -include:"c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std;c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog;c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\Z8Encore_F640X"
#   -list -NOlistmac -name -pagelen:56 -pagewidth:80 -quiet -sdiopt
#   -warn -NOzmasm -revaa -cpu:Z8F6403
AFLAGS = -sw:M:\Documents\GitHub\Programming-project-exercies\HelloWorld_Debug.asmsw

OUTDIR = M:\Documents\GitHub\Programming-project-exercies\

Debug: HelloWorld

deltarget: 
	@if exist M:\Documents\GitHub\Programming-project-exercies\HelloWorld.lod  \
            del M:\Documents\GitHub\Programming-project-exercies\HelloWorld.lod

clean: 
	@if exist M:\Documents\GitHub\Programming-project-exercies\HelloWorld.lod  \
            del M:\Documents\GitHub\Programming-project-exercies\HelloWorld.lod
	@if exist M:\Documents\GitHub\Programming-project-exercies\zsldevinit.obj  \
            del M:\Documents\GitHub\Programming-project-exercies\zsldevinit.obj
	@if exist M:\Documents\GitHub\Programming-project-exercies\main.obj  \
            del M:\Documents\GitHub\Programming-project-exercies\main.obj
	@if exist M:\Documents\GitHub\Programming-project-exercies\ansi.obj  \
            del M:\Documents\GitHub\Programming-project-exercies\ansi.obj
	@if exist M:\Documents\GitHub\Programming-project-exercies\SineLUT.obj  \
            del M:\Documents\GitHub\Programming-project-exercies\SineLUT.obj
	@if exist M:\Documents\GitHub\Programming-project-exercies\screenio.obj  \
            del M:\Documents\GitHub\Programming-project-exercies\screenio.obj
	@if exist M:\Documents\GitHub\Programming-project-exercies\buttonio.obj  \
            del M:\Documents\GitHub\Programming-project-exercies\buttonio.obj
	@if exist M:\Documents\GitHub\Programming-project-exercies\clockio.obj  \
            del M:\Documents\GitHub\Programming-project-exercies\clockio.obj
	@if exist M:\Documents\GitHub\Programming-project-exercies\ball.obj  \
            del M:\Documents\GitHub\Programming-project-exercies\ball.obj
	@if exist M:\Documents\GitHub\Programming-project-exercies\boss.obj  \
            del M:\Documents\GitHub\Programming-project-exercies\boss.obj
	@if exist M:\Documents\GitHub\Programming-project-exercies\brick.obj  \
            del M:\Documents\GitHub\Programming-project-exercies\brick.obj
	@if exist M:\Documents\GitHub\Programming-project-exercies\game.obj  \
            del M:\Documents\GitHub\Programming-project-exercies\game.obj
	@if exist M:\Documents\GitHub\Programming-project-exercies\level.obj  \
            del M:\Documents\GitHub\Programming-project-exercies\level.obj
	@if exist M:\Documents\GitHub\Programming-project-exercies\powerup.obj  \
            del M:\Documents\GitHub\Programming-project-exercies\powerup.obj
	@if exist M:\Documents\GitHub\Programming-project-exercies\striker.obj  \
            del M:\Documents\GitHub\Programming-project-exercies\striker.obj
	@if exist M:\Documents\GitHub\Programming-project-exercies\timer.obj  \
            del M:\Documents\GitHub\Programming-project-exercies\timer.obj

rebuildall: clean Debug

relink: deltarget Debug

LIBS = 

OBJS =  \
            M:\Documents\GitHub\Programming-project-exercies\zsldevinit.obj  \
            M:\Documents\GitHub\Programming-project-exercies\main.obj  \
            M:\Documents\GitHub\Programming-project-exercies\ansi.obj  \
            M:\Documents\GitHub\Programming-project-exercies\SineLUT.obj  \
            M:\Documents\GitHub\Programming-project-exercies\screenio.obj  \
            M:\Documents\GitHub\Programming-project-exercies\buttonio.obj  \
            M:\Documents\GitHub\Programming-project-exercies\clockio.obj  \
            M:\Documents\GitHub\Programming-project-exercies\ball.obj  \
            M:\Documents\GitHub\Programming-project-exercies\boss.obj  \
            M:\Documents\GitHub\Programming-project-exercies\brick.obj  \
            M:\Documents\GitHub\Programming-project-exercies\game.obj  \
            M:\Documents\GitHub\Programming-project-exercies\level.obj  \
            M:\Documents\GitHub\Programming-project-exercies\powerup.obj  \
            M:\Documents\GitHub\Programming-project-exercies\striker.obj  \
            M:\Documents\GitHub\Programming-project-exercies\timer.obj

HelloWorld: $(OBJS)
	 $(LINK)  @M:\Documents\GitHub\Programming-project-exercies\HelloWorld_Debug.linkcmd

M:\Documents\GitHub\Programming-project-exercies\zsldevinit.obj :  \
            M:\Documents\GitHub\Programming-project-exercies\zsldevinit.asm  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\ez8dev.inc  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\gpio.inc
	 $(ASM)  $(AFLAGS) M:\Documents\GitHub\Programming-project-exercies\zsldevinit.asm

M:\Documents\GitHub\Programming-project-exercies\main.obj :  \
            M:\Documents\GitHub\Programming-project-exercies\Z8encore\ANSIproject\main.c  \
            M:\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\SineLUT.h  \
            M:\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\SuperIO.h  \
            M:\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\ansi.h  \
            M:\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\ball.h  \
            M:\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\boss.h  \
            M:\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\brick.h  \
            M:\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\buttonio.h  \
            M:\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\clockio.h  \
            M:\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\color.h  \
            M:\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\game.h  \
            M:\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\level.h  \
            M:\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\powerup.h  \
            M:\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\screenio.h  \
            M:\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\striker.h  \
            M:\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\timer.h  \
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
	 $(CC)  $(CFLAGS) M:\Documents\GitHub\Programming-project-exercies\Z8encore\ANSIproject\main.c

M:\Documents\GitHub\Programming-project-exercies\ansi.obj :  \
            M:\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\ansi.c  \
            M:\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\SineLUT.h  \
            M:\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\ansi.h  \
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
	 $(CC)  $(CFLAGS) M:\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\ansi.c

M:\Documents\GitHub\Programming-project-exercies\SineLUT.obj :  \
            M:\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\SineLUT.c  \
            M:\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\SineLUT.h  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDIO.H  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\SIO.H  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h
	 $(CC)  $(CFLAGS) M:\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\SineLUT.c

M:\Documents\GitHub\Programming-project-exercies\screenio.obj :  \
            M:\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\screenio.c  \
            M:\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\charset.h  \
            M:\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\clockio.h  \
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
	 $(CC)  $(CFLAGS) M:\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\screenio.c

M:\Documents\GitHub\Programming-project-exercies\buttonio.obj :  \
            M:\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\buttonio.c  \
            M:\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\buttonio.h  \
            M:\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\clockio.h  \
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
	 $(CC)  $(CFLAGS) M:\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\buttonio.c

M:\Documents\GitHub\Programming-project-exercies\clockio.obj :  \
            M:\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\clockio.c  \
            M:\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\clockio.h  \
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
	 $(CC)  $(CFLAGS) M:\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\clockio.c

M:\Documents\GitHub\Programming-project-exercies\ball.obj :  \
            M:\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\ball.c  \
            M:\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\SineLUT.h  \
            M:\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\ansi.h  \
            M:\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\ball.h  \
            M:\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\FIXEDM~1.H  \
            M:\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\striker.h  \
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
	 $(CC)  $(CFLAGS) M:\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\ball.c

M:\Documents\GitHub\Programming-project-exercies\boss.obj :  \
            M:\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\boss.c
	 $(CC)  $(CFLAGS) M:\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\boss.c

M:\Documents\GitHub\Programming-project-exercies\brick.obj :  \
            M:\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\brick.c  \
            M:\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\ansi.h  \
            M:\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\ball.h  \
            M:\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\brick.h  \
            M:\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\color.h  \
            M:\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\striker.h  \
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
	 $(CC)  $(CFLAGS) M:\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\brick.c

M:\Documents\GitHub\Programming-project-exercies\game.obj :  \
            M:\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\game.c  \
            M:\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\SineLUT.h  \
            M:\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\SuperIO.h  \
            M:\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\ansi.h  \
            M:\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\ball.h  \
            M:\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\boss.h  \
            M:\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\brick.h  \
            M:\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\buttonio.h  \
            M:\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\clockio.h  \
            M:\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\color.h  \
            M:\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\game.h  \
            M:\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\level.h  \
            M:\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\powerup.h  \
            M:\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\screenio.h  \
            M:\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\striker.h  \
            M:\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\timer.h  \
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
	 $(CC)  $(CFLAGS) M:\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\game.c

M:\Documents\GitHub\Programming-project-exercies\level.obj :  \
            M:\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\level.c  \
            M:\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\ansi.h  \
            M:\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\ball.h  \
            M:\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\boss.h  \
            M:\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\brick.h  \
            M:\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\FIXEDM~1.H  \
            M:\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\level.h  \
            M:\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\powerup.h  \
            M:\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\striker.h  \
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
	 $(CC)  $(CFLAGS) M:\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\level.c

M:\Documents\GitHub\Programming-project-exercies\powerup.obj :  \
            M:\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\powerup.c  \
            M:\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\ansi.h  \
            M:\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\powerup.h  \
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
	 $(CC)  $(CFLAGS) M:\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\powerup.c

M:\Documents\GitHub\Programming-project-exercies\striker.obj :  \
            M:\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\striker.c  \
            M:\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\SineLUT.h  \
            M:\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\ansi.h  \
            M:\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\ball.h  \
            M:\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\color.h  \
            M:\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\FIXEDM~1.H  \
            M:\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\striker.h  \
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
	 $(CC)  $(CFLAGS) M:\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\striker.c

M:\Documents\GitHub\Programming-project-exercies\timer.obj :  \
            M:\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\timer.c  \
            M:\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\clockio.h  \
            M:\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\timer.h  \
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
	 $(CC)  $(CFLAGS) M:\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\timer.c

