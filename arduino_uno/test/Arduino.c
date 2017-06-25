#include <printf.h>
#include "Arduino.h"

unsigned long milliseconds = 0UL;

Byte INPUT = 0;
Byte OUTPUT = 1;

unsigned long millis () {
  return milliseconds++;
}

int digitalRead (Byte pin) {
  return (Byte) (milliseconds % 2);
}

void digitalWrite (Byte pin, Byte value) {
  printf ("wrote %d to pin %d\n", value, pin);
}

void pinMode(Byte pin, Byte mode) {
  printf("pin mode of %d pin set to %d\n", pin, mode);
}