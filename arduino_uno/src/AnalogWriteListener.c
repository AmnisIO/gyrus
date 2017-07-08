#include <RivuletListernerManager.h>
#include "AnalogWriteListener.h"

static void _next (RivuletListener *self, int value) {
  AnalogWriteListener *listener = (AnalogWriteListener *) self;
  int output = value;
  if (output < GYRUS_SIGNAL_LEVEL_LOW) output = GYRUS_SIGNAL_LEVEL_LOW;
  else if (output > GYRUS_SIGNAL_LEVEL_HIGH) output = GYRUS_SIGNAL_LEVEL_HIGH;
  if (listener->_started) return analogWrite (listener->pin, output);
  analogWrite (listener->pin, GYRUS_SIGNAL_LEVEL_LOW);
  pinMode (listener->pin, GYRUS_PIN_MODE_OUTPUT);
  listener->_started = GYRUS_TRUE;
  analogWrite (listener->pin, output);
}

static void _error (RivuletListener *self, int e) {
  // ignore
}

static void _complete (RivuletListener *self) {
  // ignore
}

RivuletListener *analog_write_listener_create (Pin pin) {
  AnalogWriteListener *listener = xmalloc (sizeof (AnalogWriteListener));
  rivulet_listener_initialize ((RivuletListener *) listener, _next, _error, _complete);
  listener->pin = pin;
  listener->_started = GYRUS_FALSE;
  return (RivuletListener *) listener;
}