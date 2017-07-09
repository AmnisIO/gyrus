#include <RivuletStream.h>
#include "RivuletTimer.h"
#include <Arduino.h>
#include <RivuletProducerRegistry.h>
#include <RivuletListenerRegistry.h>
#include "AnalogReadProducer.h"

static void _pin_read (void *self) {
  AnalogReadProducer *producer = self;
  int value = analogRead (producer->_pin);
  RivuletListener *listener = producer->_listener;
  rivulet_listener_registry_get_next (listener) (listener, value);
}

static void _start (RivuletProducer *self, RivuletListener *listener) {
  AnalogReadProducer *producer = (AnalogReadProducer *) self;
  producer->_listener = listener;
  producer->_task_id = rivulet_timer->set_interval (_pin_read, producer, 1);
  pinMode (producer->_pin, GYRUS_PIN_MODE_INPUT);
}

static void _stop (RivuletProducer *self) {
  AnalogReadProducer *producer = (AnalogReadProducer *) self;
  rivulet_timer->clear_task (producer->_task_id);
}

static Boolean _registered = 0;
static RivuletListenerType _listener_type = 0;
static RivuletProducerType _producer_type = 0;

static void _register () {
  if (_registered) return;
  _producer_type = rivulet_producer_registry_register (_start, _stop);
  _registered = 1;
}

AnalogReadProducer *analog_read_producer_create (Pin pin) {
  AnalogReadProducer *producer = xmalloc (sizeof (AnalogReadProducer));
  _register ();
  producer->listener_type = _listener_type;
  producer->producer_type = _producer_type;
  producer->_pin = pin;
  return producer;
}

RivuletStream *analog_read_stream_create (Pin pin) {
  return rivulet_stream_create ((RivuletProducer *) analog_read_producer_create (pin));
}
