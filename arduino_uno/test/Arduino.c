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

int A0 = 14;
int A1 = 15;
int A2 = 16;
int A3 = 17;
int A4 = 18;
int A5 = 19;

unsigned long millis () {
  return milliseconds++;
}

int digitalRead (int pin) {
  int value = (int) (milliseconds % 2);
  printf("read %d from pin %d\n", value, pin);
  return value;
}

void digitalWrite (int pin, int value) {
  printf ("wrote %d to pin %d\n", value, pin);
}

int analogRead (int pin) {
  int value = (int) (milliseconds % 2);
  printf("read %d from pin %d\n", value, pin);
  return value;
}

void analogWrite (int pin, int value) {
  printf ("wrote %d to pin %d\n", value, pin);
}

void pinMode(int pin, Boolean mode) {
  printf("pin mode of %d pin set to %d\n", pin, mode);
}