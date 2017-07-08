#include <RivuletStream.h>
#include "RivuletTimer.h"
#include <Arduino.h>
#include "DigitalReadProducer.h"

static void _pin_read (void *self) {
  DigitalReadProducer *producer = self;
  rivulet_listener_internal_next next = rivulet_listener_internal_next_get (producer->_listener);
  int value = digitalRead (producer->_pin);
  int input = value == GYRUS_SIGNAL_LEVEL_LOW ? GYRUS_SIGNAL_LEVEL_LOW: GYRUS_SIGNAL_LEVEL_HIGH;
  next (producer->_listener, input);
}

static void _pin_read_start (RivuletProducer *self, RivuletListenerInternal *listener) {
  DigitalReadProducer *producer = (DigitalReadProducer *) self;
  producer->_listener = listener;
  producer->_task_id = rivulet_timer->set_interval (_pin_read, producer, 1);
  pinMode (producer->_pin, GYRUS_PIN_MODE_INPUT);
}

static void _pin_read_stop (RivuletProducer *self) {
  DigitalReadProducer *producer = (DigitalReadProducer *) self;
  rivulet_timer->clear_task (producer->_task_id);
}

DigitalReadProducer *digital_read_producer_create (Pin pin) {
  DigitalReadProducer *producer = xmalloc (sizeof (DigitalReadProducer));
  rivulet_producer_initialize ((RivuletProducer *) producer, _pin_read_start, _pin_read_stop);
  producer->_pin = pin;
  return producer;
}

RivuletStream *digital_read_stream_create (Pin pin) {
  return rivulet_stream_create ((RivuletProducer *) digital_read_producer_create (pin));
}
