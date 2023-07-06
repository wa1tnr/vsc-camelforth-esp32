#!/bin/sh

# ${1}  is /dev/ttyACM0   5 July 2023 at 21:04 UTC

# arduino-cli upload --fqbn arduino:renesas_uno:unor4wifi -p ${1}
cd ./camelforth-a
arduino-cli upload --fqbn arduino:renesas_uno:unor4wifi -p /dev/ttyACM0

exit 0

arduino-cli compile --fqbn arduino:renesas_uno:unor4wifi ${1}
arduino-cli compile --fqbn arduino:renesas_uno:minima ${1}
