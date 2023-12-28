/* n_sk_camelforth.cpp */
/* Wed 27 Dec 01:42:27 UTC 2023 */

#include "common.h"
#include <Arduino.h>

#define SERIAL_FORTH Serial

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
    // SERIAL_FORTH.println("DID SEE THIS LINE 101");
    SERIAL_FORTH.write(ch);
    return (unsigned int)ch;
  }
}

void putch(unsigned int c) {
  /* comment about all three keyboard chars specified 0x7f 0x8 &c. */
#ifdef WOKWI_VSCODE
  int result = c - 8;
  bool isBackspace = result == 0;
  bool notBackspace = !isBackspace;

  if (isBackspace) {
    SERIAL_FORTH.write(0x08);
    SERIAL_FORTH.write(0x20);
  }

  if (notBackspace) {
    SERIAL_FORTH.write(0x08);
  }

#endif // #ifdef WOKWI_VSCODE
  char q = (char)c;
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
  digitalWrite(LED_BUILTIN, 1);
  delay(70);
  digitalWrite(LED_BUILTIN, 0);
  delay(400);
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
  SERIAL_FORTH.print("\nspecific to ESP32");
  SERIAL_FORTH.print("    vsc-camelforth-esp32  ");
  SERIAL_FORTH.println(
    "\n                                 Thu 28 Dec 03:20:14 UTC 2023");
  SERIAL_FORTH.println(
    "\n\n    rev f15e4d0    shred: a   branch: wokwi-ver-aa");
  SERIAL_FORTH.println("\n\n   : nd cr dump cr ;  \\ 3F400000 dump ");

  // kinda seems like Serial1 is correct here 24 Dec 23z
  // Note: Serial1 was correct for ESP32 not UNO R4 WiFi m likely 25 Dec 23z
  // while(-1);
  trapped();
}

void loop() { ; }

/*

   Wed 27 Dec 01:46:10 UTC 2023

   arduino-cli compile --fqbn esp32:esp32:esp32

   Sketch uses 275269 bytes (21%) of program storage space. Maximum is 1310720
   bytes. Global variables use 37160 bytes (11%) of dynamic memory, leaving
   290520 bytes for local variables. Maximum is 327680 bytes.

*/

// anaconda penguin lupine wolf
// END.
