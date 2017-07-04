#ifndef GYRUS_ARDUINO_UNO_ARDUINOUNOSOURCES_H
#define GYRUS_ARDUINO_UNO_ARDUINOUNOSOURCES_H

#include <RivuletStream.h>

typedef struct Sources {
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
} Sources;

Sources *sources_create ();

#endif //GYRUS_ARDUINO_UNO_ARDUINOUNOSOURCES_H
