#include "AnalogWriteListener.h"
#include <Arduino.h>
#include <RivuletUtils.h>
#include <RivuletListenerRegistry.h>

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

static void _complete (RivuletListener *self) {
  // ignore
}

static Boolean _registered = 0;
static RivuletListenerType _listener_type = 0;
static RivuletProducerType _producer_type = 0;

static void _register () {
  if (_registered) return;
  _listener_type = rivulet_listener_registry_register (_next, _complete);
  _registered = 1;
}

RivuletListener *analog_write_listener_create (Pin pin) {
  AnalogWriteListener *listener = xmalloc (sizeof (AnalogWriteListener));
  _register ();
  listener->listener_type = _listener_type;
  listener->producer_type = _producer_type;
  listener->pin = pin;
  listener->_started = GYRUS_FALSE;
  return (RivuletListener *) listener;
}