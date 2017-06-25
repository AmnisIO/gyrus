#ifndef GYRUS_ARDUINO_UNO_ARDUINO_H
#define GYRUS_ARDUINO_UNO_ARDUINO_H

#include "Byte.h"
#include "Boolean.h"

unsigned long millis();
int digitalRead(Byte pin);
void digitalWrite(Byte pin, Byte value);
void pinMode(Byte pin, Byte mode);
extern Byte INPUT;
extern Byte OUTPUT;
extern Boolean true;
extern Boolean false;
extern Byte HIGH;
extern Byte LOW;

#endif //GYRUS_ARDUINO_UNO_ARDUINO_H
