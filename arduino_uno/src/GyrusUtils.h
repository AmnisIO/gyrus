#ifndef GYRUS_ARDUINO_UNO_GYRUSUTILS_H
#define GYRUS_ARDUINO_UNO_GYRUSUTILS_H

#include <stdint.h>

typedef uint8_t Pin;
extern const Pin GYRUS_PIN_D0;
extern const Pin GYRUS_PIN_D1;
extern const Pin GYRUS_PIN_D2;
extern const Pin GYRUS_PIN_D3;
extern const Pin GYRUS_PIN_D4;
extern const Pin GYRUS_PIN_D5;
extern const Pin GYRUS_PIN_D6;
extern const Pin GYRUS_PIN_D7;
extern const Pin GYRUS_PIN_D8;
extern const Pin GYRUS_PIN_D9;
extern const Pin GYRUS_PIN_D10;
extern const Pin GYRUS_PIN_D11;
extern const Pin GYRUS_PIN_D12;
extern const Pin GYRUS_PIN_D13;
extern const Pin GYRUS_PIN_LED;
extern const Pin GYRUS_PIN_A0;
extern const Pin GYRUS_PIN_A1;
extern const Pin GYRUS_PIN_A2;
extern const Pin GYRUS_PIN_A3;
extern const Pin GYRUS_PIN_A4;
extern const Pin GYRUS_PIN_A5;
extern const Pin GYRUS_PIN_A6;
extern const Pin GYRUS_PIN_A7;

typedef uint8_t PinMode;
extern const PinMode GYRUS_PIN_MODE_INPUT;
extern const PinMode GYRUS_PIN_MODE_OUTPUT;

typedef uint8_t SignalLevel;
extern const SignalLevel GYRUS_SIGNAL_LEVEL_LOW;
extern const SignalLevel GYRUS_SIGNAL_LEVEL_HIGH;

typedef uint8_t Boolean;
extern const Boolean GYRUS_TRUE;
extern const Boolean GYRUS_FALSE;

#endif //GYRUS_ARDUINO_UNO_GYRUSUTILS_H
