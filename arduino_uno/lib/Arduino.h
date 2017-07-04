#ifndef GYRUS_ARDUINO_UNO_ARDUINO_H
#define GYRUS_ARDUINO_UNO_ARDUINO_H

#include "Boolean.h"

unsigned long millis();
int digitalRead(int pin);
void digitalWrite(int pin, int value);
void pinMode(int pin, Boolean mode);
extern Boolean INPUT;
extern Boolean OUTPUT;
extern Boolean true;
extern Boolean false;
extern Boolean HIGH;
extern Boolean LOW;

#endif //GYRUS_ARDUINO_UNO_ARDUINO_H
