### BASE DIRECTORY for the compiled .bin

```

  (too long a commit message - split out to this file 28 Dec 2023)

  The OS provides a place to store a compiled binary.
  Local implementation uses the directory pointed to
  by the soft link in this very commit:

    /tmp/arduino

    $ ls -la | grep hex | grep compiled

    compiled_bin_hex.d -> /tmp/arduino

    (long version):

    lrwxrwxrwx  abcde  Dec 25  camelforth-a.ino.bin -> ./compiled_bin_hex.d/this_now.d/camelforth-a.ino.bin
    lrwxrwxrwx  abcde  Dec 24  camelforth-a.ino.elf -> ./compiled_bin_hex.d/this_now.d/camelforth-a.ino.elf
    lrwxrwxrwx  abcde  Dec 24  compiled_bin_hex.d -> /tmp/arduino

    THE 'this_now.d' LINK IS ALSO ONE MAINTAINED BY THE END USER,
    including creation.  Seems to persist between sessions (File > Exit).



  Do expect the implementation to be quite specific to the
  OS and other factors.  Not hard to find (in Linux) but must
  be identified and accounted for.

  Chosen method in this commit is to use a 'soft link' which is
  routine for Linux.

	new file:   compiled_bin_hex.d

On branch dvlp-aa
```
