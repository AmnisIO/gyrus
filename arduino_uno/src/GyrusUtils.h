#ifndef GYRUS_ARDUINO_UNO_GYRUSUTILS_H
#define GYRUS_ARDUINO_UNO_GYRUSUTILS_H

#include <stdint.h>

typedef uint8_t Pin;
const Pin GYRUS_PIN_D0;
const Pin GYRUS_PIN_D1;
const Pin GYRUS_PIN_D2;
const Pin GYRUS_PIN_D3;
const Pin GYRUS_PIN_D4;
const Pin GYRUS_PIN_D5;
const Pin GYRUS_PIN_D6;
const Pin GYRUS_PIN_D7;
const Pin GYRUS_PIN_D8;
const Pin GYRUS_PIN_D9;
const Pin GYRUS_PIN_D10;
const Pin GYRUS_PIN_D11;
const Pin GYRUS_PIN_D12;
const Pin GYRUS_PIN_D13;
const Pin GYRUS_PIN_LED;
const Pin GYRUS_PIN_A0;
const Pin GYRUS_PIN_A1;
const Pin GYRUS_PIN_A2;
const Pin GYRUS_PIN_A3;
const Pin GYRUS_PIN_A4;
const Pin GYRUS_PIN_A5;
const Pin GYRUS_PIN_A6;
const Pin GYRUS_PIN_A7;

typedef uint8_t PinMode;
const PinMode GYRUS_PIN_MODE_INPUT;
const PinMode GYRUS_PIN_MODE_OUTPUT;

typedef uint8_t SignalLevel;
const SignalLevel GYRUS_SIGNAL_LEVEL_LOW;
const SignalLevel GYRUS_SIGNAL_LEVEL_HIGH;

typedef uint8_t Boolean;
const Boolean GYRUS_TRUE;
const Boolean GYRUS_FALSE;

#endif //GYRUS_ARDUINO_UNO_GYRUSUTILS_H
