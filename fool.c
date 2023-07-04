/* fool.c */
/* Tue  4 Jul 15:25:40 UTC 2023 */
/* is this file deprecated yet? */
/* mostly hardware blinking LEDs from another project. */

/* Used as scaffolding before SerialUSB.print() was found */
/* to be effective, locally. */

int state;

void toggle_LED(int pinNumber) {
  state = !state;
  digitalWrite(pinNumber, state);
}

void slowest() {
  for (volatile int iter = 9800; iter > 1; iter--) {
    ;
  }
}

void slower() {
  for (volatile int repeating = 25;
       repeating > 0; repeating--) {
    slowest();
  }
}

void this_here_now() {
  toggle_LED(13);
  slower();
  toggle_LED(13);
  for (int off_to_on_ratio = 7; off_to_on_ratio > 1; off_to_on_ratio--) {
    slower();
  }
  int test = 0;
  for (test = 22; test > 0; test--) {
    ;
  }
}

void this_here() {
  while (-1) {
    this_here_now();  // loop
  }
}
/* end */
