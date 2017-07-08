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

SignalLevel LOW;
SignalLevel HIGH;

#endif //GYRUS_ARDUINO_UNO_ARDUINO_H
