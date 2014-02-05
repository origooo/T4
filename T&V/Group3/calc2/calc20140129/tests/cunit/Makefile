SRCPATH = ../../src
SRCOBJS = $(wildcard $(SRCPATH)/*.o)
TESTSRCS = $(wildcard *.c)

cunit: testsuite
	@echo Running tests...
	./cunitrunner

testsuite.o: $(TESTSRCS)
	gcc -c unitmain.c -o testsuite.o $(ECTRAGCCFLAGS)

testsuite: $(SRCOBJS) testsuite.o
	gcc $(SRCOBJS) testsuite.o -o cunitrunner $(EXTRAGCCFLAGS) -lcunit 

clean:
	rm -f cunitrunner cunitrunner.exe testsuite.o

