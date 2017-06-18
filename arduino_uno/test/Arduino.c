#include "Arduino.h"

unsigned long milliseconds = 0UL;

unsigned long millis() {
  return milliseconds++;
}

int digitalRead(Byte pin) {
  return pin;
}