#
# Makefile for the Linix TCP/IP (INET) layer.
#
# Note! Dependencies are done automagically by 'make dep', which also
# removes any old dependencies. DON'T put your own dependencies here
# unless it's something special (ie not a .c file).
#
# Note 2! The CFLAGS definition is now in the main makefile...

CC	=gcc -mcpu=i386
CFLAGS	=-Wall -O -g -fstrength-reduce -fomit-frame-pointer \
	-finline-functions -nostdinc -I../../include -I../include  -I../inet -I.
AS	=as
AR	=ar
LD	=ld
CPP	=gcc -E -nostdinc -I../include

.c.o:
	$(CC) $(CFLAGS) \
	-c -o $*.o $<
.s.o:
	$(AS) -o $*.o $<
.c.s:
	$(CC) $(CFLAGS) \
	-S -o $*.s $<


OBJS	= ne.o 8390.o


driver.o:		$(OBJS)
		$(LD) -r -o driver.o $(OBJS)

dep:
		$(CPP) -M *.c > .depend

tar:
		tar -cvf /dev/f1 .

#
# include a dependency file if one exists
#
ifeq (.depend,$(wildcard .depend))
include .depend
endif

clean:
		rm *.o -rf
