#include <RivuletListernerManager.h>
#include <Arduino.h>
#include "DigitalWriteListener.h"

static void _next (RivuletListener *self, int value) {
  DigitalWriteListener *listener = (DigitalWriteListener *) self;
  SignalLevel output = value == GYRUS_SIGNAL_LEVEL_LOW ? LOW : HIGH;
  if (listener->_started) return digitalWrite (listener->pin, output);
  digitalWrite (listener->pin, LOW);
  pinMode (listener->pin, GYRUS_PIN_MODE_OUTPUT);
  listener->_started = GYRUS_TRUE;
  digitalWrite (listener->pin, output);
}

static void _complete (RivuletListener *self) {
  // ignore
}

RivuletListener *digital_write_listener_create (Pin pin) {
  DigitalWriteListener *listener = xmalloc (sizeof (DigitalWriteListener));
  rivulet_listener_initialize ((RivuletListener *) listener, _next, _complete);
  listener->pin = pin;
  listener->_started = GYRUS_FALSE;
  return (RivuletListener *) listener;
}