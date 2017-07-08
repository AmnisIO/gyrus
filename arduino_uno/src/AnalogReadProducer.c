#include <RivuletStream.h>
#include "RivuletTimer.h"
#include <Arduino.h>
#include "AnalogReadProducer.h"

static void _pin_read (void *self) {
  AnalogReadProducer *producer = self;
  rivulet_listener_internal_next next = rivulet_listener_internal_next_get (producer->_listener);
  int value = analogRead (producer->_pin);
  next (producer->_listener, value);
}

static void _pin_read_start (RivuletProducer *self, RivuletListenerInternal *listener) {
  AnalogReadProducer *producer = (AnalogReadProducer *) self;
  producer->_listener = listener;
  producer->_task_id = rivulet_timer->set_interval (_pin_read, producer, 1);
  pinMode (producer->_pin, GYRUS_PIN_MODE_INPUT);
}

static void _pin_read_stop (RivuletProducer *self) {
  AnalogReadProducer *producer = (AnalogReadProducer *) self;
  rivulet_timer->clear_task (producer->_task_id);
}

AnalogReadProducer *analog_read_producer_create (Pin pin) {
  AnalogReadProducer *producer = xmalloc (sizeof (AnalogReadProducer));
  rivulet_producer_initialize ((RivuletProducer *) producer, _pin_read_start, _pin_read_stop);
  producer->_pin = pin;
  return producer;
}

RivuletStream *analog_read_stream_create (Pin pin) {
  return rivulet_stream_create ((RivuletProducer *) analog_read_producer_create (pin));
}
