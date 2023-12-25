#!/bin/sh
export LOCAL_ACLI_DIRECTOR_Y_PROJ_ECT="./camelforth-a"

prequel() {
    echo
    echo " make clean does this:"
    echo
    echo " rm -rf /tmp/arduino/cores ; rm -rf /tmp/arduino/sketches  # elbee"
    echo

cat << _EOF

    RUNNING:

        arduino-cli compile --fqbn esp32:esp32:esp32 ${1}
        # arduino-cli compile --fqbn arduino:renesas_uno:unor4wifi ${1}
        # ESP32 Dev Module     esp32:esp32:esp32

_EOF

    arduino-cli compile --fqbn esp32:esp32:esp32 \
         ${LOCAL_ACLI_DIRECTOR_Y_PROJ_ECT}

exit 0
}

prequel

exit 0

# end.
