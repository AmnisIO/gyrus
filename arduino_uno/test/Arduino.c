#include <printf.h>
#include <RivuletTask.h>
#include "Arduino.h"

unsigned long milliseconds = 0UL;

Boolean INPUT = 0;
Boolean OUTPUT = 1;
Boolean true = 1;
Boolean false = 0;
Boolean HIGH = 1;
Boolean LOW = 0;

Pin A0 = 14;
Pin A1 = 15;
Pin A2 = 16;
Pin A3 = 17;
Pin A4 = 18;
Pin A5 = 19;

unsigned long millis () {
  return milliseconds++;
}

int digitalRead (Pin pin) {
  int value = (int) (milliseconds % 2);
  printf("read %d from pin %d\n", value, pin);
  return value;
}

void digitalWrite (Pin pin, int value) {
  printf ("wrote %d to pin %d\n", value, pin);
}

int analogRead (Pin pin) {
  int value = (int) (milliseconds % 2);
  printf("read %d from pin %d\n", value, pin);
  return value;
}

void analogWrite (Pin pin, int value) {
  printf ("wrote %d to pin %d\n", value, pin);
}

void pinMode(Pin pin, Boolean mode) {
  printf("pin mode of %d pin set to %d\n", pin, mode);
}