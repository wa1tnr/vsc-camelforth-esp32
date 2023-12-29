/* n_sk_camelforth.cpp */

#include "common.h"
#include <Arduino.h>
#define SERIAL_FORTH Serial

/* Fri 29 Dec 01:09:37 UTC 2023 */

#ifdef __cplusplus
extern "C" {
#endif

void this_here();
void interpreter(void);
extern void this_here_now();

#if 0
// mass delete of unused code - compile before commit
#endif

char getch(void) {
  bool waiting_ch = 0;

  // for (int testing = 5; testing > 0; testing--) { ; }

  while (!waiting_ch) {
    bool waiting_now = SERIAL_FORTH.available();
    waiting_ch = waiting_now;
  }

  if (waiting_ch) {
    unsigned int ch = SERIAL_FORTH.read();
    SERIAL_FORTH.write(ch);
    return (unsigned int)ch;
  }

  if (!waiting_ch) {
    SERIAL_FORTH.println(" TRAP LINE 114");
    while(-1);
  }
  /* TODO: fixme - zero clue so faking it: */
  char pch='\0';
  return (unsigned int)pch;

  // TODO: suss - nothing reaches here - compiler says control reaches end of non-void function.
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
  interpreter();
  while (-1)
    ;
}

void setup() {
  delay(2200);
  pinMode(LED_BUILTIN, OUTPUT);
  SERIAL_FORTH.begin(115200);
  SERIAL_FORTH.print("\r\n specific to ESP32");
  SERIAL_FORTH.print("     vsc-camelforth-esp32  ");
  SERIAL_FORTH.print( "\r\n ");
  SERIAL_FORTH.print(__DATE__);
  SERIAL_FORTH.print( "   ");
  SERIAL_FORTH.print(__TIME__);
  SERIAL_FORTH.println( " UTC");
  SERIAL_FORTH.print("\r\n     rev d735870    shred: a   branch: dvlp-aa\r\n");
  SERIAL_FORTH.println("\r\n   : nd cr dump cr ;  \\ hex 3F400000 dump\r\n");
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

// kraton brogan crayola nearfetched
// END.
