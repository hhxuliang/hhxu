#
# Makefile for the Linix TCP/IP (INET) layer.
#
# Note! Dependencies are done automagically by 'make dep', which also
# removes any old dependencies. DON'T put your own dependencies here
# unless it's something special (ie not a .c file).
#
# Note 2! The CFLAGS definition is now in the main makefile...

CC	=gcc -mcpu=i386
CFLAGS	=-Wall -g -O -fstrength-reduce -fomit-frame-pointer \
	-finline-functions -nostdinc -I../../include -I../include -I. -I../driver
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


OBJS	= sock.o dev.o skbuff.o eth.o loopback.o raw.o ip.o arp.o icmp.o \
			utils.o route.o packet.o protocol.o datagram.o proc.o timer.o udp.o tcp.o 

inet.o:		$(OBJS)
		$(LD) -r -o inet.o $(OBJS)

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
