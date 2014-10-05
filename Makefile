COMPILER = gcc
CCFLAGS = -Wall -g
AR = ar

all: sv_max

sv_max: test.o libsvmax.a
	$(COMPILER) $(CCFLAGS) test.o libsvmax.a -o sv

libsvmax.a: max_sv.o
	$(AR) -r libsvmax.a max_sv.o

max_sv.o:
	$(COMPILER) $(CCFLAGS) -c max_sv.c max_sv.h

test.o:
	$(COMPILER) $(CCFLAGS) -c test.c

clean:
	rm *.o *.a *.gch sv
