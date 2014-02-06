calc: calc.h calc.c main.c
	gcc -o calc calc.c main.c $(EXTRAGCCFLAGS)

testobjs: calc.h calc.c 
	gcc -o calc.o -c calc.c $(EXTRAGCCFLAGS)

gcov: EXTRAGCCFLAGS+= -fprofile-arcs -ftest-coverage
gcov: testobjs

gdb: EXTRAGCCFLAGS+= -g
gdb: testobjs calc

clean:
	rm -f calc calc.exe calc.o *.gcno *.gcov *.gcda
