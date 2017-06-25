#include <ByteListener.h>
#include <Boolean.h>

#ifndef GYRUS_ARDUINO_UNO_DIGITALWRITELISTENER_H
#define GYRUS_ARDUINO_UNO_DIGITALWRITELISTENER_H

typedef struct DigitalWriteListener {
  ByteObservableType type;
  byte_listener_internal_next _next;
  byte_listener_internal_error _error;
  byte_listener_internal_complete _complete;
  byte_listener_next next;
  byte_listener_error error;
  byte_listener_complete complete;
  Byte pin;
  Boolean _started;
} DigitalWriteListener;

ByteListener *digital_write_listener_create(Byte pin);

#endif //GYRUS_ARDUINO_UNO_DIGITALWRITELISTENER_H
