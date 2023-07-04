#include "api/Common.h"
#include "USB/USBAPI.h"
#include <Arduino.h>
/* Mon  3 Jul 18:56:20 UTC 2023 */

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
      return (unsigned int) ch;
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
  SerialUSB.println("as in git repo Tue  4 Jul 11:44:18 UTC 2023");
  trapped();
}

void loop() {
  ;
}
// lupine
// END.
