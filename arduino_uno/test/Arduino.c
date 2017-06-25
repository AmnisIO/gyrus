#include <printf.h>
#include "Arduino.h"

unsigned long milliseconds = 0UL;

Byte INPUT = 0;
Byte OUTPUT = 1;
Boolean true = 1;
Boolean false = 0;
Byte HIGH = 1;
Byte LOW = 0;

unsigned long millis () {
  return milliseconds++;
}

int digitalRead (Byte pin) {
  Byte value = (Byte) (milliseconds % 2);
  printf("read %d from pin %d\n", value, pin);
  return value;
}

void digitalWrite (Byte pin, Byte value) {
  printf ("wrote %d to pin %d\n", value, pin);
}

void pinMode(Byte pin, Byte mode) {
  printf("pin mode of %d pin set to %d\n", pin, mode);
}