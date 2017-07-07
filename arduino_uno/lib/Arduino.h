#ifndef GYRUS_ARDUINO_UNO_ARDUINO_H
#define GYRUS_ARDUINO_UNO_ARDUINO_H

#include "Boolean.h"

unsigned long millis();
int digitalRead(int pin);
int analogRead(int pin);
void digitalWrite(int pin, int value);
void analogWrite(int pin, int value);
void pinMode(int pin, Boolean mode);
extern Boolean INPUT;
extern Boolean OUTPUT;
extern Boolean true;
extern Boolean false;
extern Boolean HIGH;
extern Boolean LOW;

extern int A0;
extern int A1;
extern int A2;
extern int A3;
extern int A4;
extern int A5;

#endif //GYRUS_ARDUINO_UNO_ARDUINO_H
