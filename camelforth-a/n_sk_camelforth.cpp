/* n_sk_camelforth.cpp */
/* Thu  6 Jul 02:47:55 UTC 2023 */

      // bool waiting_now = SerialUSB.available();

// #include "api/Common.h"
// what was this for then // #include "USB/USBAPI.h"
#include <Arduino.h>
// #define SERIAL_FORTH SerialUSB

// #define SERIAL_FORTH Serial1
#define SERIAL_FORTH Serial

/* Mon  3 Jul 18:56:20 UTC 2023 */

#ifdef __cplusplus
extern "C" {
#endif

void this_here();
void interpreter(void);
extern void this_here_now();

void print_message(char *message) {
    char buffer[32];
    snprintf(buffer, 31, "%s", message, '\000');
    SERIAL_FORTH.print(buffer);
}

void print_message_no_nl(char *message) {
    char buffer[32];
    snprintf(buffer, 31, "%s", message, '\000');
    SERIAL_FORTH.print(buffer);
}

void print_the_address(unsigned int *p) {
    char buffer[12];
    snprintf(buffer, 11, "\n%8x:", p, '\000');
    SERIAL_FORTH.print(buffer);
}

void print_the_addr_no_nl(unsigned int *p) {
    char buffer[12];
    snprintf(buffer, 11, "%8x:", p, '\000');
    SERIAL_FORTH.print(buffer);
}

void print_each_number(unsigned int *p) {
    char buffer[12];
    buffer[0] = '\000';
    snprintf(buffer, 11, "  %8X", *p, '\000');
    SERIAL_FORTH.print(buffer);
}

void print_dump_addr(unsigned char *p) {
    char buffer[24];
    buffer[0] = '\000';
    snprintf(buffer, 23, "\n%8x:", p,
             '\000'); // address at beginning of 16-byte line
    SERIAL_FORTH.print(buffer);
}

void print_dumped_char(unsigned char *p) {
    char buffer[24];
    buffer[0] = '\000';
    snprintf(buffer, 23, "%c", p, '\000');
    SERIAL_FORTH.print(buffer);
}

void print_dumped_byte(unsigned char *p) {
    char buffer[24];
    buffer[0] = '\000';
    snprintf(buffer, 23, " %02x", *p, '\000');
    SERIAL_FORTH.print(buffer);
}

void print_dumped_byte_no_nl(unsigned char *p) {
    char buffer[5];
    buffer[0] = '\000';
    snprintf(buffer, 4, "%02x", *p, '\000');
    SERIAL_FORTH.print(buffer);
}

/*
  sample run - DUMP word  - line count on TOS

  HEX EEDDCCBB 20 40 60 CR .S CR
  HEX 200024D4 30 - 40 DUMP CR .S

*/

char getch(void) {
    bool waiting_ch = 0;
    // for (int testing = 5; testing > 0; testing--) { ; }
    while (!waiting_ch) {
        bool waiting_now = SERIAL_FORTH.available();
        waiting_ch = waiting_now;
    }
    if (waiting_ch) {
        unsigned int ch = SERIAL_FORTH.read();
        SERIAL_FORTH.println("DID SEE THIS LINE 101");
        SERIAL_FORTH.write(ch);
        return (unsigned int)ch;
    }
}

void putch(unsigned int c) {
    char *q;
    q = (char *)c;
    SERIAL_FORTH.write(q);
}

int getquery(void) {
    // return(UARTCharsAvail(UART0_BASE) != 0);
    return (0 != 0);
}

#ifndef LED_BUILTIN
#define LED_BUILTIN 15
#endif

void blinker() {
    // for (int count = 2; count > 0; count--) {
    digitalWrite(LED_BUILTIN, 1);
    delay(70);
    digitalWrite(LED_BUILTIN, 0);
    delay(400);
    // }
}

// void make_it_reset() { NVIC_SystemReset(); }
void make_it_reset() { ; }

#ifdef __cplusplus
}
#endif

void talker() { SERIAL_FORTH.println("jobs"); }

void trapped() {
    for (int count = 3; count > 0; count--) {
        blinker();
    }
    // talker();
    interpreter();
    while (-1)
        ;
}

void setup() {
    delay(2200);
    pinMode(LED_BUILTIN, OUTPUT);
    SERIAL_FORTH.begin(115200);
    SERIAL_FORTH.print("\nspecific to Arduino Uno R4 WiFi");
    SERIAL_FORTH.print("    vsc-camelforth-uno-r4wifi  ");
    SERIAL_FORTH.println(
        "\n                                 Sun 25 Dec 02:52:47 UTC 2023");
    SERIAL_FORTH.println("\n\n    rev f15e4d0    shred: a   branch: wokwi-ver-aa");
    SERIAL_FORTH.println("\n\n   : nd CR DUP DUMP 10 + ;  \ 200024DC next dump ");
    // kinda seems like Serial1 is correct here 24 Dec 23z
    // Note: Serial1 was correct for ESP32 not UNO R4 WiFi m likely 25 Dec 23z
    // while(-1);
    trapped();
}

void loop() { ; }

/*
   REDO ME

   Sketch uses 33060 bytes (12%) of program storage space. Maximum is 262144
   bytes. Global variables use 18744 bytes (57%) of dynamic memory, leaving
   14024 bytes for local variables. Maximum is 32768 bytes.
*/

// lupine wolfe bat walrus
// END.
