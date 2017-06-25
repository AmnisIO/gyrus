#ifndef GYRUS_ARDUINO_UNO_ARDUINOUNOSOURCES_H
#define GYRUS_ARDUINO_UNO_ARDUINOUNOSOURCES_H

#include <ByteStream.h>

typedef struct Sources {
  ByteStream *D1;
  ByteStream *D2;
  ByteStream *D3;
  ByteStream *D4;
  ByteStream *D5;
  ByteStream *D6;
  ByteStream *D7;
  ByteStream *D8;
  ByteStream *D9;
  ByteStream *D10;
  ByteStream *D11;
  ByteStream *D12;
  ByteStream *D13;
  ByteStream *LED;
} Sources;

Sources *sources_create ();

#endif //GYRUS_ARDUINO_UNO_ARDUINOUNOSOURCES_H
