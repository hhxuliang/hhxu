CC	=gcc -mcpu=i386
CFLAGS	=-Wall  -g -fstrength-reduce -fomit-frame-pointer \
	-finline-functions -nostdinc -I../include -I./include -I. -I./driver -I./inet
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

OBJS	= ddi.o space.o socket.o 

SUBDIRS     := inet driver

SUBOBJS     := $(foreach f,$(SUBDIRS),$f/$f.o)

all: subdirs net.o

net.o: $(OBJS) driver/driver.o inet/inet.o
	$(LD) -r -o net.o $(OBJS) driver/driver.o inet/inet.o

driver/driver.o:
	(cd ./driver;make)

inet/inet.o:
	(cd ./inet;make)

subdirs:	dummy	
	set -e; for i in $(SUBDIRS); do $(MAKE) -C $$i; done

dep:
	sed '/\#\#\# Dependencies/q' < Makefile > tmp_make
	(for i in *.c;do $(CPP) -M $$i;done) >> tmp_make
	cp tmp_make Makefile

dummy:

#
# include a dependency file if one exists
#
ifeq (.depend,$(wildcard .depend))
include .depend
endif

clean:
	(cd ./driver;make clean)
	(cd ./inet;make clean)
	rm -f core *.o *.a tmp_make