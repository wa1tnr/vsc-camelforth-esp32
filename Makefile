

# targettte:	clean compile_only
# targettte:	clean compile_verbose

targettte:	clean compile_verbose
	@echo
	@date
	@echo
	@sha1sum ./camelforth-a.ino.bin
	@echo

all:

install:
	@./upload.sh

compile_verbose:
	@echo COMPILE VERBOSE
	@./compile_verbose.sh

compile_only:
	@echo COMPILE ONLY
	@./compile.sh

board:
	@arduino-cli board listall

comm:
	./cf-fastpico9t-esp32-vsc.sh /dev/ttyACM0

clean:
	rm -rf /tmp/arduino/cores ; rm -rf /tmp/arduino/sketches

# end.
