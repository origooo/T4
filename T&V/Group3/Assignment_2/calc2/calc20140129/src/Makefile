compile: calc.h calc.c main.c
	gcc -o calc calc.c main.c $(EXTRAGCCFLAGS)
	@echo "  "
	@echo "Run binary by typing src/calc"

compile-c89: calc.h calc.c main.c
	gcc -std=gnu89  -o calc calc.c main.c $(EXTRAGCCFLAGS)
	@echo "  "
	@echo "Run binary by typing src/calc"

testobjs: calc.h calc.c 
	gcc -o calc.o -c calc.c $(EXTRAGCCFLAGS)

testobjs-c89: calc.h calc.c 
	gcc -std=gnu89 -o calc.o -c calc.c $(EXTRAGCCFLAGS)

gdb: EXTRAGCCFLAGS+= -g
gdb: calc

clean:
	rm -f calc calc.exe calc.o
