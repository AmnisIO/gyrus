#include <RivuletListernerManager.h>
#include "AnalogWriteListener.h"
#include "SignalLevels.h"

static void _next (RivuletListener *self, int value) {
  AnalogWriteListener *listener = (AnalogWriteListener *) self;
  int output = value;
  if (output < GYRUS_LOW) output = GYRUS_LOW;
  else if (output > GYRUS_HIGH) output = GYRUS_HIGH;
  if (listener->_started) return analogWrite (listener->pin, output);
  analogWrite (listener->pin, LOW);
  pinMode (listener->pin, OUTPUT);
  listener->_started = true;
  analogWrite (listener->pin, output);
}

static void _error (RivuletListener *self, int e) {
  // ignore
}

static void _complete (RivuletListener *self) {
  // ignore
}

RivuletListener *analog_write_listener_create (int pin) {
  AnalogWriteListener *listener = xmalloc (sizeof (AnalogWriteListener));
  rivulet_listener_initialize ((RivuletListener *) listener, _next, _error, _complete);
  listener->pin = pin;
  listener->_started = false;
  return (RivuletListener *) listener;
}