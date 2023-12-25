

targettte:	clean
	@./compile.sh

all:

install:
	@./upload.sh

board:
	@arduino-cli board listall

comm:
	./cf-fastpico9t-esp32-vsc.sh /dev/ttyACM0

clean:
	@echo so this is make clean right here
	rm -rf /tmp/arduino/cores ; rm -rf /tmp/arduino/sketches

# end.
