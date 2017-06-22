#include <printf.h>
#include "Arduino.h"

unsigned long milliseconds = 0UL;

unsigned long millis () {
  return milliseconds++;
}

int digitalRead (Byte pin) {
  return pin;
}

void digitalWrite (Byte pin, Byte value) {
  printf ("wrote %d to pin %d\n", value, pin);
}