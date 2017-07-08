#ifndef GYRUS_ARDUINO_UNO_DIGITALWRITELISTENER_H
#define GYRUS_ARDUINO_UNO_DIGITALWRITELISTENER_H

#include <RivuletListener.h>
#include <Boolean.h>
#include "GyrusUtils.h"

typedef struct DigitalWriteListener {
  RivuletObservableType type;
  rivulet_listener_internal_next _next;
  rivulet_listener_internal_complete _complete;
  rivulet_listener_next next;
  rivulet_listener_complete complete;
  Pin pin;
  Boolean _started;
} DigitalWriteListener;

RivuletListener *digital_write_listener_create(Pin pin);

#endif //GYRUS_ARDUINO_UNO_DIGITALWRITELISTENER_H
