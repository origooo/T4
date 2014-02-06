default:
	@echo "--- Normal compilation ----------------------------------"
	@echo "make calc     produces binary in src/"
	@echo " "
	@echo "--- Cleaning up -----------------------------------------"
	@echo "make clean    recursively clean up subdirs"
	@echo " "
	@echo "--- Verification and debugging --------------------------"
	@echo "make unit      run unit tests"
	@echo " "
	@echo "--- Test coverage ---------------------------------------"
	@echo "make gcov      run unit tests with code coverage"
	@echo " "
	@echo "--- Valgrind --------------------------------------------"
	@echo "make gdb       compile with debugging flags"

calc:
	cd src && $(MAKE) calc

clean:
	cd src && $(MAKE) clean
	cd tests/unit && $(MAKE) clean

gcov:
	cd src && $(MAKE) gcov
	cd tests/unit && $(MAKE) gcov

gdb:
	cd src && $(MAKE) gdb
	cd tests/unit && $(MAKE) gdb

unit:
	cd src && $(MAKE) testobjs
	cd tests/unit && $(MAKE) unit
