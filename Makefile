

targettte:	clean
	@./compile.sh

all:

install:
	@./upload.sh

comm:
	./cf-fastpico9t-black_pill /dev/ttyACM0

clean:
	@echo so this is make clean right here
	rm -rf /tmp/arduino/cores ; rm -rf /tmp/arduino/sketches

# end.
