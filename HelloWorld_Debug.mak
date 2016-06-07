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
#   -stdinc:"c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include;c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog"
#   -strict
#   -usrinc:"M:\Documents\GitHub\Programming-project-exercies\Z8encore\include"
#   -NOwatch -cpu:Z8F6403
#   -asmsw:" -cpu:Z8F6403 -define:_Z8F6403=1 -define:_Z8ENCORE_640_FAMILY=1 -define:_Z8ENCORE_F640X=1 -define:_MODEL_LARGE=1 -include:c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include;c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog -revaa"
CFLAGS = -sw:M:\Documents\GitHub\Programming-project-exercies\HelloWorld_Debug.ccsw
# assembler options
#   -debug -define:_Z8F6403=1 -define:_Z8ENCORE_640_FAMILY=1
#   -define:_Z8ENCORE_F640X=1 -define:_MODEL_LARGE=1 -genobj -NOigcase
#   -include:"c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include;c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog"
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
	@if exist M:\Documents\GitHub\Programming-project-exercies\ansi.obj  \
            del M:\Documents\GitHub\Programming-project-exercies\ansi.obj
	@if exist M:\Documents\GitHub\Programming-project-exercies\SineLUT.obj  \
            del M:\Documents\GitHub\Programming-project-exercies\SineLUT.obj
	@if exist M:\Documents\GitHub\Programming-project-exercies\main.obj  \
            del M:\Documents\GitHub\Programming-project-exercies\main.obj

rebuildall: clean Debug

relink: deltarget Debug

LIBS = 

OBJS =  \
            M:\Documents\GitHub\Programming-project-exercies\zsldevinit.obj  \
            M:\Documents\GitHub\Programming-project-exercies\ansi.obj  \
            M:\Documents\GitHub\Programming-project-exercies\SineLUT.obj  \
            M:\Documents\GitHub\Programming-project-exercies\main.obj

HelloWorld: $(OBJS)
	 $(LINK)  @M:\Documents\GitHub\Programming-project-exercies\HelloWorld_Debug.linkcmd

M:\Documents\GitHub\Programming-project-exercies\zsldevinit.obj :  \
            M:\Documents\GitHub\Programming-project-exercies\zsldevinit.asm  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\ez8dev.inc  \
            c:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\gpio.inc
	 $(ASM)  $(AFLAGS) M:\Documents\GitHub\Programming-project-exercies\zsldevinit.asm

M:\Documents\GitHub\Programming-project-exercies\ansi.obj :  \
            M:\Documents\GitHub\Programming-project-exercies\Z8encore\include\src\ansi.c  \
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

M:\Documents\GitHub\Programming-project-exercies\main.obj :  \
            M:\Documents\GitHub\Programming-project-exercies\Z8encore\ANSIproject\main.c  \
            M:\DOCUME~1\GitHub\PROGRA~2\Z8encore\include\SineLUT.h  \
            M:\DOCUME~1\GitHub\PROGRA~2\Z8encore\include\SuperIO.h  \
            M:\DOCUME~1\GitHub\PROGRA~2\Z8encore\include\ansi.h  \
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

