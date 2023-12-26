

targettte:	clean
	@./compile.sh
	@echo
	@date
	@echo
	@sha1sum ./camelforth-a.ino.bin
	@echo

all:

install:
	@./upload.sh

board:
	@arduino-cli board listall

comm:
	./cf-fastpico9t-esp32-vsc.sh /dev/ttyACM0

clean:
	rm -rf /tmp/arduino/cores ; rm -rf /tmp/arduino/sketches

# end.
