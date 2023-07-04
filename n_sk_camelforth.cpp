/* n_sk_camelforth.cpp */
/* Tue  4 Jul 15:25:40 UTC 2023 */

#include "api/Common.h"
#include "USB/USBAPI.h"
#include <Arduino.h>

#ifdef __cplusplus
extern "C" {
#endif

  void this_here();
  void interpreter(void);
  extern void this_here_now();

  void print_the_address(unsigned int *p) {
    // unsigned int *q = p;
    char buffer[12];
    snprintf(buffer, 11, "\n%8x:", p, '\000');
    SerialUSB.print(buffer);
  }

  void print_each_number(unsigned int *p) {
    // unsigned int* q = (unsigned int*) *p;
    char buffer[12];
    buffer[0] = '\000';
    snprintf(buffer, 11, "  %8X", *p, '\000');
    SerialUSB.print(buffer);
  }

  void print_dump_addr(unsigned char *p) {
    char buffer[24];
    buffer[0] = '\000';
    snprintf(buffer, 23, "\n%8x:", p, '\000');  // address at beginning of 16-byte line
    SerialUSB.print(buffer);
    // printf("\n%8x:", (unsigned int)p);
  }

  void print_dumped_byte(unsigned char *p) {
    char buffer[24];
    buffer[0] = '\000';
    snprintf(buffer, 23, " %02x", *p, '\000');
    // printf(" %02x", *p++);
    SerialUSB.print(buffer);
  }

  /*
     sample run - DUMP word  - line count on TOS

    HEX EEDDCCBB 20 40 60 CR .S CR
    HEX 200027D4 30 - 40 DUMP CR .S

    specific to Arduino M0 Pro   as in git repo Tue  4 Jul 15:19:22 UTC 2023
    CamelForth in C v0.1 - 14 Feb 2016
    HEX EEDDCCBB 20 40 60 CR .S CR

    200027d4:  EEDDCCBB        20        40        60

    ok HEX 200027D4 30 - 40 DUMP CR .S
    200027a4: 10 00 00 00 01 00 00 00 05 00 00 00 00 00 00 00
    200027b4: ff ff ff ff ff ff ff ff 30 05 00 20 40 00 00 00
    200027c4: a4 27 00 20 60 00 00 00 40 00 00 00 20 00 00 00
    200027d4: bb cc dd ee 00 00 00 00 48 45 58 20 32 30 30 30

    200027d4:  EEDDCCBB        20        40        60
    ok
  */

  char getch(void) {
    bool waiting_ch = 0;
    for (int testing = 5; testing > 0; testing--) {
      ;
    }
    while (!waiting_ch) {
      bool waiting_now = SerialUSB.available();
      waiting_ch = waiting_now;
    }
    if (waiting_ch) {
      unsigned int ch = SerialUSB.read();
      return (unsigned int)ch;
    }
  }

  void putch(char c) {
    SerialUSB.write(c);
    // printf("%c", c);
    return;  // doesn't have to do anything
  }

  int getquery(void) {
    // return(UARTCharsAvail(UART0_BASE) != 0);
    return (0 != 0);
  }

  void blinker() {
    for (int count = 2; count > 0; count--) {
      digitalWrite(LED_BUILTIN, 1);
      delay(90);
      digitalWrite(LED_BUILTIN, 0);
      delay(700);
    }
  }

#ifdef __cplusplus
}
#endif

void talker() {
  SerialUSB.println("jobs");
}

void trapped() {
  // blinker();
  // talker();
  interpreter();
  while (-1)
    ;
}

void setup() {
  delay(2200);
  pinMode(LED_BUILTIN, OUTPUT);
  SerialUSB.begin(115200);
  // SerialUSB.print("\nCamelforth in C   ");
  SerialUSB.print("\nspecific to Arduino M0 Pro   ");
  SerialUSB.println("as in git repo Tue  4 Jul 15:41:21 UTC 2023 a");
  trapped();
}

void loop() {
  ;
}

/*
   Sketch uses 33060 bytes (12%) of program storage space. Maximum is 262144 bytes.
   Global variables use 18744 bytes (57%) of dynamic memory, leaving 14024 bytes for local variables. Maximum is 32768 bytes.
*/

// lupine wolfe bat
// END.
