#include <ByteListernerManager.h>
#include "DigitalWriteListener.h"
#include "Arduino.h"

static void _digital_write_next (ByteListener *self, Byte value) {
  DigitalWriteListener *listener = (DigitalWriteListener *) self;
  if(listener->_started == false) {
    pinMode (listener->pin, OUTPUT);
    listener->_started = true;
  }
  digitalWrite (listener->pin, value);
}

static void _digital_write_error (ByteListener *self, int e) {
  // ignore
}

static void _digital_write_complete (ByteListener *self) {
  // ignore
}

ByteListener *digital_write_listener_create (Byte pin) {
  DigitalWriteListener *listener = xmalloc (sizeof (DigitalWriteListener));
  byte_listener_initialize ((ByteListener *) listener, _digital_write_next, _digital_write_error,
                            _digital_write_complete);
  listener->pin = pin;
  listener->_started = false;
  return (ByteListener *) listener;
}