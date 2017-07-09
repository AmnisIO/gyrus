#include <RivuletStream.h>
#include "RivuletTimer.h"
#include <Arduino.h>
#include <RivuletListenerRegistry.h>
#include <RivuletProducerRegistry.h>
#include "DigitalReadProducer.h"

static void _pin_read (void *self) {
  DigitalReadProducer *producer = self;
  int value = digitalRead (producer->_pin);
  int input = value == GYRUS_SIGNAL_LEVEL_LOW ? GYRUS_SIGNAL_LEVEL_LOW : GYRUS_SIGNAL_LEVEL_HIGH;
  RivuletListener *listener = producer->_listener;
  rivulet_listener_registry_get_next (listener) (listener, input);
}

static void _start (RivuletProducer *self, RivuletListener *listener) {
  DigitalReadProducer *producer = (DigitalReadProducer *) self;
  producer->_listener = listener;
  producer->_task_id = rivulet_timer->set_interval (_pin_read, producer, 1);
  pinMode (producer->_pin, GYRUS_PIN_MODE_INPUT);
}

static void _stop (RivuletProducer *self) {
  DigitalReadProducer *producer = (DigitalReadProducer *) self;
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

DigitalReadProducer *digital_read_producer_create (Pin pin) {
  DigitalReadProducer *producer = xmalloc (sizeof (DigitalReadProducer));
  _register ();
  producer->listener_type = _listener_type;
  producer->producer_type = _producer_type;
  producer->_pin = pin;
  return producer;
}

RivuletStream *digital_read_stream_create (Pin pin) {
  return rivulet_stream_create ((RivuletProducer *) digital_read_producer_create (pin));
}
