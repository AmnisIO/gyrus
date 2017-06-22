#include <ByteStream.h>
#include "RivuletTimer.h"
#include "Arduino.h"
#include "DigitalReadProducer.h"

static void _pin_read (void *self) {
  DigitalReadProducer *producer = self;
  byte_listener_internal_next next = byte_listener_internal_next_get (producer->_listener);
  Byte value = (Byte) digitalRead (producer->_pin);
  next (producer->_listener, value);
}

static void _pin_read_start (ByteProducer *self, ByteListenerInternal *listener) {
  DigitalReadProducer *producer = (DigitalReadProducer *) self;
  producer->_listener = listener;
  producer->_task_id = rivulet_timer->set_interval (_pin_read, producer, 1);
}

static void _pin_read_stop (ByteProducer *self) {
  DigitalReadProducer *producer = (DigitalReadProducer *) self;
  rivulet_timer->clear_task (producer->_task_id);
}

DigitalReadProducer *digital_read_producer_create (Byte pin) {
  DigitalReadProducer *producer = xmalloc (sizeof (DigitalReadProducer));
  byte_producer_initialize ((ByteProducer *) producer, _pin_read_start, _pin_read_stop);
  producer->_pin = pin;
  return producer;
}

ByteStream *digital_read_stream_create (Byte pin) {
  return byte_stream_create ((ByteProducer *) digital_read_producer_create (pin));
}
