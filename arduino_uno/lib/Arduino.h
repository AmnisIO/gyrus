#ifndef GYRUS_ARDUINO_UNO_ARDUINO_H
#define GYRUS_ARDUINO_UNO_ARDUINO_H

#include "Boolean.h"
#include "Pin.h"

unsigned long millis();
int digitalRead(Pin pin);
int analogRead(Pin pin);
void digitalWrite(Pin pin, int value);
void analogWrite(Pin pin, int value);
void pinMode(Pin pin, Boolean mode);
extern Boolean INPUT;
extern Boolean OUTPUT;
extern Boolean true;
extern Boolean false;
extern Boolean HIGH;
extern Boolean LOW;

extern Pin A0;
extern Pin A1;
extern Pin A2;
extern Pin A3;
extern Pin A4;
extern Pin A5;

#endif //GYRUS_ARDUINO_UNO_ARDUINO_H
