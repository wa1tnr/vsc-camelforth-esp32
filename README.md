### Thu 28 Dec 03:34:07 UTC 2023

All improvements - config for wokwi web not vsc extension:

  https://wokwi.com/projects/385326088908112897

  a day older or so:

  https://wokwi.com/projects/385236933484103681

  a little older (minutes):

  https://wokwi.com/projects/385235714680085505

 - - -

#### legacy comments follow.

 - - -


seems very good on wokwi web, worried it is borked
for vscode, though:

  https://wokwi.com/projects/385217785649688577

light commented:

  https://wokwi.com/projects/385215933871767553

  It 'works' but prints the backspaces which is
  not wanted.  Not tested on vscode in 90+ minutes.

add switch working in wokwi webbed:

  https://wokwi.com/projects/385215561541296129

works on wokwi webbed:

  https://wokwi.com/projects/385207337838423041

was: Sun 25 Dec 01:21:06 UTC 2023

exp - wokwi test of vscode-friendly keyboard heuristics:

  https://wokwi.com/projects/385200503426340865

Result: dismal!  Do not do this this way ;)
Ok: sync'd to current work, so just edit forth.c
and n_sk_foo.cpp to get it right for wokwi web.


stable / is:

  https://wokwi.com/projects/385046318994525185
  
was:

  https://wokwi.com/projects/385045842725008385

was: Thu  6 Jul 21:45:22 UTC 2023




Thu  6 Jul 21:45:22 UTC 2023

NEWS:  DUMP works better and no longer accepts a line count.

Tue  4 Jul 15:25:40 UTC 2023

CamelForth in C

Arduino IDE 2.1.1    xwayland (xeyes follows it)    Debian bookworm amd64

DUMP seems to be reasonably correct.
The DOTS (.S) word seems fine now.

Both may have an address misalignment by .. four bytes, say.
They seem to agree and make sense as-presented (15:25 UTC 4 July 2023).


Older notes follow.

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
