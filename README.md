Tue  4 Jul 12:39:05 UTC 2023

CamelForth in C

Arduino IDE 2.1.1    xwayland (xeyes follows it)    Debian bookworm amd64

Compiles 'visually' clean in the IDE (did not check warnings from defaults yet).

Runs on Arduino M0 Pro (vintage unit on-hand).  May be significant
undiscovered errors.  Recent work was to get the .S word (dots)
working semi-correctly.

The hard part is figuring out where Arduino and C++ specific things
get their data from - passing parameters and such between the two
very distinct domains (Camelforth, in C, is compiled likely to an
object file, very much like an included .s assembler file would be).

Good enough to download, compile and try for yourself.

Seem to be doing a lot of ARM + Arduino IDE ports of this program,
lately. ;)

TODO: markdown this file at least a little ;)

END
