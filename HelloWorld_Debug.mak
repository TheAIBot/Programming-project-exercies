#
# ZDS II Make File - HelloWorld, Debug
#

CC = @D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore\bin\eZ8cc
ASM = @D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore\bin\eZ8asm
LINK = @D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore\bin\eZ8link
LIB = @D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore\bin\eZ8lib

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
#   -stdinc:"D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore\include\std;D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore\include\zilog;D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore\include\zilog\Z8Encore_F640X"
#   -strict
#   -usrinc:"M:\Documents\GitHub\Programming-project-exercies\Z8encore\include;C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\Z8encore\include"
#   -NOwatch -cpu:Z8F6403
#   -asmsw:" -cpu:Z8F6403 -define:_Z8F6403=1 -define:_Z8ENCORE_640_FAMILY=1 -define:_Z8ENCORE_F640X=1 -define:_MODEL_LARGE=1 -include:D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore\include\std;D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore\include\zilog;D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore\include\zilog\Z8Encore_F640X -revaa"
CFLAGS = -sw:C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\HelloWorld_Debug.ccsw
# assembler options
#   -debug -define:_Z8F6403=1 -define:_Z8ENCORE_640_FAMILY=1
#   -define:_Z8ENCORE_F640X=1 -define:_MODEL_LARGE=1 -genobj -NOigcase
#   -include:"D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore\include\std;D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore\include\zilog;D:\ProgramFiles\ZiLOG\ZDSIIZ8Encore\include\zilog\Z8Encore_F640X"
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
	@if exist C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\SineLUT.obj  \
            del C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\SineLUT.obj

rebuildall: clean Debug

relink: deltarget Debug

LIBS = 

OBJS =  \
            C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\zsldevinit.obj  \
            C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\main.obj  \
            C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\ansi.obj  \
            C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\SineLUT.obj

HelloWorld: $(OBJS)
	 $(LINK)  @C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\HelloWorld_Debug.linkcmd

C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\zsldevinit.obj :  \
            C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\zsldevinit.asm  \
            D:\PROGRA~3\ZiLOG\ZDSIIZ~1\include\zilog\ez8dev.inc  \
            D:\PROGRA~3\ZiLOG\ZDSIIZ~1\include\zilog\gpio.inc
	 $(ASM)  $(AFLAGS) C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\zsldevinit.asm

C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\main.obj :  \
            C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\Z8encore\ANSIproject\main.c  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\SineLUT.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\SuperIO.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\ansi.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\charset.h  \
            D:\PROGRA~3\ZiLOG\ZDSIIZ~1\include\std\format.h  \
            D:\PROGRA~3\ZiLOG\ZDSIIZ~1\include\std\stdarg.h  \
            D:\PROGRA~3\ZiLOG\ZDSIIZ~1\include\std\stdio.h  \
            D:\PROGRA~3\ZiLOG\ZDSIIZ~1\include\zilog\defines.h  \
            D:\PROGRA~3\ZiLOG\ZDSIIZ~1\include\zilog\dmadefs.h  \
            D:\PROGRA~3\ZiLOG\ZDSIIZ~1\include\zilog\eZ8.h  \
            D:\PROGRA~3\ZiLOG\ZDSIIZ~1\include\zilog\gpio.h  \
            D:\PROGRA~3\ZiLOG\ZDSIIZ~1\include\zilog\sio.h  \
            D:\PROGRA~3\ZiLOG\ZDSIIZ~1\include\zilog\uart.h  \
            D:\PROGRA~3\ZiLOG\ZDSIIZ~1\include\zilog\uartdefs.h
	 $(CC)  $(CFLAGS) C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\Z8encore\ANSIproject\main.c

C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\ansi.obj :  \
            C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\ansi.c  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\SineLUT.h  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\ansi.h  \
            D:\PROGRA~3\ZiLOG\ZDSIIZ~1\include\std\format.h  \
            D:\PROGRA~3\ZiLOG\ZDSIIZ~1\include\std\stdarg.h  \
            D:\PROGRA~3\ZiLOG\ZDSIIZ~1\include\std\stdio.h  \
            D:\PROGRA~3\ZiLOG\ZDSIIZ~1\include\zilog\defines.h  \
            D:\PROGRA~3\ZiLOG\ZDSIIZ~1\include\zilog\dmadefs.h  \
            D:\PROGRA~3\ZiLOG\ZDSIIZ~1\include\zilog\eZ8.h  \
            D:\PROGRA~3\ZiLOG\ZDSIIZ~1\include\zilog\gpio.h  \
            D:\PROGRA~3\ZiLOG\ZDSIIZ~1\include\zilog\sio.h  \
            D:\PROGRA~3\ZiLOG\ZDSIIZ~1\include\zilog\uart.h  \
            D:\PROGRA~3\ZiLOG\ZDSIIZ~1\include\zilog\uartdefs.h
	 $(CC)  $(CFLAGS) C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\ansi.c

C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\SineLUT.obj :  \
            C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\SineLUT.c  \
            C:\Users\Andreas\DOCUME~1\GitHub\PROGRA~1\Z8encore\include\SineLUT.h  \
            D:\PROGRA~3\ZiLOG\ZDSIIZ~1\include\std\format.h  \
            D:\PROGRA~3\ZiLOG\ZDSIIZ~1\include\std\stdarg.h  \
            D:\PROGRA~3\ZiLOG\ZDSIIZ~1\include\std\stdio.h  \
            D:\PROGRA~3\ZiLOG\ZDSIIZ~1\include\zilog\defines.h  \
            D:\PROGRA~3\ZiLOG\ZDSIIZ~1\include\zilog\sio.h  \
            D:\PROGRA~3\ZiLOG\ZDSIIZ~1\include\zilog\uart.h  \
            D:\PROGRA~3\ZiLOG\ZDSIIZ~1\include\zilog\uartdefs.h
	 $(CC)  $(CFLAGS) C:\Users\Andreas\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\SineLUT.c

