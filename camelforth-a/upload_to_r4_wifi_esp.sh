#!/bin/sh

# ${1}  is /dev/ttyACM0   5 July 2023 at 21:04 UTC

arduino-cli upload --fqbn arduino:renesas_uno:unor4wifi -p ${1}
exit 0

arduino-cli compile --fqbn arduino:renesas_uno:unor4wifi ${1}
arduino-cli compile --fqbn arduino:renesas_uno:minima ${1}
# vetted 24 Dec 2023 - fine as it - exit 0 <verbs> execution below it.