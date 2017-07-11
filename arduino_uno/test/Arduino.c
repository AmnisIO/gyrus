#include <printf.h>
#include <Rivulet.h>
#include <GyrusUtils.h>
#include "Arduino.h"

unsigned long milliseconds = 0UL;

unsigned long millis () {
  return milliseconds++;
}

int digitalRead (Pin pin) {
  int value = (int) (milliseconds % 2);
  printf("read %d from pin %d\n", value, pin);
  return value;
}

void digitalWrite (Pin pin, SignalLevel value) {
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

void pinMode(Pin pin, PinMode mode) {
  printf("pin mode of %d pin set to %d\n", pin, mode);
}