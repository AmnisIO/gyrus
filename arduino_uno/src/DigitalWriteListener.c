#include <Arduino.h>
#include <RivuletUtils.h>
#include <RivuletListenerRegistry.h>
#include "DigitalWriteListener.h"

static void _next (RivuletListener *self, int value) {
  DigitalWriteListener *listener = (DigitalWriteListener *) self;
  SignalLevel output = (SignalLevel) (value == GYRUS_SIGNAL_LEVEL_LOW ? LOW : HIGH);
  if (listener->_started) return digitalWrite (listener->pin, output);
  digitalWrite (listener->pin, LOW);
  pinMode (listener->pin, GYRUS_PIN_MODE_OUTPUT);
  listener->_started = GYRUS_TRUE;
  digitalWrite (listener->pin, output);
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

RivuletListener *digital_write_listener_create (Pin pin) {
  DigitalWriteListener *listener = xmalloc (sizeof (DigitalWriteListener));
  _register ();
  listener->listener_type = _listener_type;
  listener->producer_type = _producer_type;
  listener->pin = pin;
  listener->_started = GYRUS_FALSE;
  return (RivuletListener *) listener;
}