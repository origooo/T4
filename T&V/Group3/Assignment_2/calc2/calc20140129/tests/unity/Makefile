SRCPATH = ../../src
SRCOBJS = $(wildcard $(SRCPATH)/*.o)
TESTSRCS = unitytest.c unity/src/unity.c

#$(wildcard *.c)

unity:
	@echo ""
	@echo "Running tests..."
	./unityrunner

testsuite.o: $(TESTSRCS)
	gcc -c $(TESTSRCS) -o testsuite.o $(ECTRAGCCFLAGS)

testsuite: $(SRCOBJS) testsuite.o
	gcc $(SRCOBJS) testsuite.o -o unityrunner $(EXTRAGCCFLAGS) 

clean:
	rm -f unityrunner unityrunner.exe testsuite.o

