#ifndef GYRUS_ARDUINO_UNO_ARDUINOUNOSINKS_H
#define GYRUS_ARDUINO_UNO_ARDUINOUNOSINKS_H

#include <RivuletStream.h>

typedef struct Sinks {
  RivuletStream *D1;
  RivuletStream *D2;
  RivuletStream *D3;
  RivuletStream *D4;
  RivuletStream *D5;
  RivuletStream *D6;
  RivuletStream *D7;
  RivuletStream *D8;
  RivuletStream *D9;
  RivuletStream *D10;
  RivuletStream *D11;
  RivuletStream *D12;
  RivuletStream *D13;
  RivuletStream *LED;
} Sinks;

Sinks *sinks_create ();

#endif //GYRUS_ARDUINO_UNO_ARDUINOUNOSINKS_H
