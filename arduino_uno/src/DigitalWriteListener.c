#include <RivuletListernerManager.h>
#include <Arduino.h>
#include "DigitalWriteListener.h"
#include "SignalLevels.h"

static void _next (RivuletListener *self, int value) {
  DigitalWriteListener *listener = (DigitalWriteListener *) self;
  int output = value == GYRUS_LOW ? LOW : HIGH;
  if (listener->_started) return digitalWrite (listener->pin, output);
  digitalWrite (listener->pin, LOW);
  pinMode (listener->pin, OUTPUT);
  listener->_started = true;
  digitalWrite (listener->pin, output);
}

static void _error (RivuletListener *self, int e) {
  // ignore
}

static void _complete (RivuletListener *self) {
  // ignore
}

RivuletListener *digital_write_listener_create (int pin) {
  DigitalWriteListener *listener = xmalloc (sizeof (DigitalWriteListener));
  rivulet_listener_initialize ((RivuletListener *) listener, _next, _error, _complete);
  listener->pin = pin;
  listener->_started = false;
  return (RivuletListener *) listener;
}