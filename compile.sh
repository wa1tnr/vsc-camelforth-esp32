#!/bin/sh
export LOCAL_ACLI_DIRECTOR_Y_PROJ_ECT="./camelforth-a"

prequel_a() {
    echo
    echo " make clean does this:"
    echo
    echo " rm -rf /tmp/arduino/cores ; rm -rf /tmp/arduino/sketches  # elbee"
    echo
}

prequel_b() {
    cat << _EOF

    RUNNING:

        arduino-cli compile --fqbn esp32:esp32:esp32 ${1}

_EOF
}
prequel_c() {
    cat << _EOF
        # arduino-cli compile --fqbn arduino:renesas_uno:unor4wifi ${1}
        # ESP32 Dev Module     esp32:esp32:esp32

_EOF
}

payload() {
    arduino-cli compile --fqbn esp32:esp32:esp32 \
         ${LOCAL_ACLI_DIRECTOR_Y_PROJ_ECT}
}

prequel() { # pick and choose
    # prequel_a
    prequel_b
    # prequel_c
}

prequel ; payload

exit 0

# end.
