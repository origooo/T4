SRCPATH = ../../src
SRCOBJS = $(wildcard $(SRCPATH)/*.o)
TESTSRCS = $(wildcard *.c)

unit: testsuite
	@echo Running tests...
	./testsuite

testsuite.o: $(TESTSRCS)
	gcc -c unitmain.c -o testsuite.o $(EXTRAGCCFLAGS)

testsuite: $(SRCOBJS) testsuite.o
	gcc $(SRCOBJS) testsuite.o -g -o testsuite $(EXTRAGCCFLAGS) -lcunit 

gcov: EXTRAGCCFLAGS+= -fprofile-arcs -ftest-coverage
gcov: unit

gdb: EXTRAGCCFLAGS+= -g
gdb: unit

clean:
	rm -f testsuite testsuite.exe testsuite.o *.gcda *.gcno

