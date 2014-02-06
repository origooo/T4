UNITYRUNNER=tests/unity/unityrunner

default:
	@echo "--- Normal compilation ----------------------------------"
	@echo "make compile         compile binary in src/"
	@echo "make compile-c89     compile binary in src/ with C89 flags"
	@echo "                     (for e.g. latest versions of OS X)"
	@echo " "
	@echo "--- Cleaning up -----------------------------------------"
	@echo "make clean           recursively clean up subdirs"
	@echo " "
	@echo "--- Verification and debugging --------------------------"
	@echo "make cunit           compile and run CUnit tests"
	@echo "make cunit-c89       compile and run CUnit tests (C89 flags)"
	@echo "make unity           compile and run Unity tests"
	@echo "make unity-c89       compile and run Unity tests (C89 flags)"


compile:
	cd src && $(MAKE) compile

compile-c89:
	cd src && $(MAKE) compile-c89

clean:
	cd src && $(MAKE) clean
	cd tests/cunit && $(MAKE) clean
	cd tests/unity && $(MAKE) clean

cunit:
	cd src && $(MAKE) testobjs
	cd tests/cunit && $(MAKE) cunit

cunit-c89:
	cd src && $(MAKE) testobjs-c89
	cd tests/cunit && $(MAKE) cunit

unity:
	gcc -w src/calc.c tests/unity/unity/src/unity.c tests/unity/unityrunner.c \
	-o tests/unity/unityrunner
	@echo ""
	@echo "Running Unity tests..."
	tests/unity/unityrunner

unity-c89:
	gcc -std=gnu89 -w src/calc.c tests/unity/unity/src/unity.c tests/unity/unityrunner.c \
	-o tests/unity/unityrunner
	@echo ""
	@echo "Running Unity tests..."
	tests/unity/unityrunner
