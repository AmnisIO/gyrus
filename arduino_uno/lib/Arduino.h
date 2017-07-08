#ifndef GYRUS_ARDUINO_UNO_ARDUINO_H
#define GYRUS_ARDUINO_UNO_ARDUINO_H

#include "Boolean.h"
#include "GyrusUtils.h"

unsigned long millis();
void pinMode(Pin, PinMode);
void digitalWrite(Pin, SignalLevel);
int digitalRead(Pin);
int analogRead(Pin);
void analogWrite(Pin, int);

#define HIGH 0x1
#define LOW  0x0

#define INPUT 0x0
#define OUTPUT 0x1
#define INPUT_PULLUP 0x2

#endif //GYRUS_ARDUINO_UNO_ARDUINO_H
