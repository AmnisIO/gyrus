#ifndef GYRUS_ARDUINO_UNO_ANALOGWRITELISTENER_H
#define GYRUS_ARDUINO_UNO_ANALOGWRITELISTENER_H

#include <RivuletListener.h>
#include <Boolean.h>
#include "GyrusUtils.h"

typedef struct AnalogWriteListener {
  RivuletListenerType listener_type;
  RivuletProducerType producer_type;
  Pin pin;
  Boolean _started;
} AnalogWriteListener;

RivuletListener *analog_write_listener_create (Pin pin);

#endif //GYRUS_ARDUINO_UNO_ANALOGWRITELISTENER_H
