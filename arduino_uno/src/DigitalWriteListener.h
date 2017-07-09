#ifndef GYRUS_ARDUINO_UNO_DIGITALWRITELISTENER_H
#define GYRUS_ARDUINO_UNO_DIGITALWRITELISTENER_H

#include <RivuletListener.h>
#include <Boolean.h>
#include "GyrusUtils.h"

typedef struct DigitalWriteListener {
  RivuletListenerType listener_type;
  RivuletProducerType producer_type;
  Pin pin;
  Boolean _started;
} DigitalWriteListener;

RivuletListener *digital_write_listener_create(Pin pin);

#endif //GYRUS_ARDUINO_UNO_DIGITALWRITELISTENER_H
