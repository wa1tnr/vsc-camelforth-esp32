

targettte:	clean
	@./compile.sh

all:

install:
	@./upload.sh

board:
	@arduino-cli board listall

comm:
	./cf-fastpico9t-uno_r4_wifi.sh /dev/ttyACM0

clean:
	@echo so this is make clean right here
	rm -rf /tmp/arduino/cores ; rm -rf /tmp/arduino/sketches

# end.
