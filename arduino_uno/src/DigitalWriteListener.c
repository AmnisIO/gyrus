#include <ByteListernerManager.h>
#include "DigitalWriteListener.h"
#include "Arduino.h"

static void _next (ByteListener *self, Byte value) {
  DigitalWriteListener *listener = (DigitalWriteListener *) self;
  Byte output = value == LOW ? LOW : HIGH;
  if (listener->_started) return digitalWrite (listener->pin, output);
  digitalWrite (listener->pin, LOW);
  pinMode (listener->pin, OUTPUT);
  listener->_started = true;
  digitalWrite (listener->pin, output);
}

static void _error (ByteListener *self, int e) {
  // ignore
}

static void _complete (ByteListener *self) {
  // ignore
}

ByteListener *digital_write_listener_create (Byte pin) {
  DigitalWriteListener *listener = xmalloc (sizeof (DigitalWriteListener));
  byte_listener_initialize ((ByteListener *) listener, _next, _error, _complete);
  listener->pin = pin;
  listener->_started = false;
  return (ByteListener *) listener;
}