#include <ByteListernerManager.h>
#include "DigitalWriteListener.h"
#include "Arduino.h"

static void _digital_write_next (ByteListener *self, Byte value) {
  DigitalWriteListener *listener = (DigitalWriteListener *) self;
  digitalWrite (listener->pin, value);
}

static void _digital_write_error (ByteListener *self, int e) {
  // ignore
}

static void _digital_write_complete (ByteListener *self) {
  // ignore
}

DigitalWriteListener *digital_write_listener_create (Byte pin) {
  DigitalWriteListener *listener = xmalloc (sizeof (DigitalWriteListener));
  byte_listener_initialize ((ByteListener *) listener, _digital_write_next, _digital_write_error,
                            _digital_write_complete);
  listener->pin = pin;
  return listener;
}