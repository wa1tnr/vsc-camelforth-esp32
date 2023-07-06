/* n_sk_camelforth.cpp */
/* Thu  6 Jul 02:47:55 UTC 2023 */

#include "api/Common.h"
#include <Arduino.h>

#ifdef __cplusplus
extern "C" {
#endif

void this_here();
void interpreter(void);
extern void this_here_now();

void print_message(char *message) {
    char buffer[32];
    snprintf(buffer, 31, "%s", message, '\000');
    Serial.print(buffer);
}

void print_message_no_nl(char *message) {
    char buffer[32];
    snprintf(buffer, 31, "%s", message, '\000');
    Serial.print(buffer);
}

void print_the_address(unsigned int *p) {
    char buffer[12];
    snprintf(buffer, 11, "\n%8x:", p, '\000');
    Serial.print(buffer);
}

void print_the_addr_no_nl(unsigned int *p) {
    char buffer[12];
    snprintf(buffer, 11, "%8x:", p, '\000');
    Serial.print(buffer);
}

void print_each_number(unsigned int *p) {
    char buffer[12];
    buffer[0] = '\000';
    snprintf(buffer, 11, "  %8X", *p, '\000');
    Serial.print(buffer);
}

void print_dump_addr(unsigned char *p) {
    char buffer[24];
    buffer[0] = '\000';
    snprintf(buffer, 23, "\n%8x:", p,
             '\000'); // address at beginning of 16-byte line
    Serial.print(buffer);
}

void print_dumped_char(unsigned char *p) {
    char buffer[24];
    buffer[0] = '\000';
    snprintf(buffer, 23, "%c", p, '\000');
    Serial.print(buffer);
}

void print_dumped_byte(unsigned char *p) {
    char buffer[24];
    buffer[0] = '\000';
    snprintf(buffer, 23, " %02x", *p, '\000');
    Serial.print(buffer);
}

void print_dumped_byte_no_nl(unsigned char *p) {
    char buffer[5];
    buffer[0] = '\000';
    snprintf(buffer, 4, "%02x", *p, '\000');
    Serial.print(buffer);
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
        bool waiting_now = Serial.available();
        waiting_ch = waiting_now;
    }
    if (waiting_ch) {
        unsigned int ch = Serial.read();
        return (unsigned int)ch;
    }
}

void putch(unsigned int c) {
    char *q;
    q = (char *)c;
    Serial.write(q);
}

int getquery(void) {
    // return(UARTCharsAvail(UART0_BASE) != 0);
    return (0 != 0);
}

void blinker() {
    // for (int count = 2; count > 0; count--) {
    digitalWrite(LED_BUILTIN, 1);
    delay(70);
    digitalWrite(LED_BUILTIN, 0);
    delay(400);
    // }
}

void make_it_reset() { NVIC_SystemReset(); }

#ifdef __cplusplus
}
#endif

void talker() { Serial.println("jobs"); }

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
    Serial.begin(115200);
    Serial.print("\nspecific to Arduino Uno R4 WiFi");
    Serial.print("    vsc-camelforth-uno-r4wifi  ");
    Serial.println(
        "\n                                 Thu  6 Jul 02:47:55 UTC 2023 c");
    Serial.println("\n\n    rev 9b55d294   shred: e");
    Serial.println("\n\n   : nd CR DUP DUMP 10 + ;  \ 200024DC next dump ");
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
