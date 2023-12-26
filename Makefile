

targettte:	clean
	@./compile.sh
	@echo
	@date
	@echo

all:

install:
	@./upload.sh

board:
	@arduino-cli board listall

comm:
	./cf-fastpico9t-esp32-vsc.sh /dev/ttyACM0

clean:
	@echo   roger - make clean begins now.
	rm -rf /tmp/arduino/cores ; rm -rf /tmp/arduino/sketches

# end.
