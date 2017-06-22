#include "RivuletTimer.h"
#include "Arduino.h"
#include "ByteListernerManager.h"
#include "ArduinoUnoInputPinByteProducer.h"

static void _pin_read (void *self) {
  ArduinoUnoInputPinByteProducer *producer = self;
  byte_listener_internal_next next = byte_listener_internal_next_get (producer->_listener);
  Byte value = (Byte) digitalRead (producer->_pin);
  next (producer->_listener, value);
}

static void _pin_read_start (ByteProducer *self, ByteListenerInternal *listener) {
  ArduinoUnoInputPinByteProducer *producer = (ArduinoUnoInputPinByteProducer *) self;
  producer->_listener = listener;
  producer->_task_id = rivulet_timer->set_interval (_pin_read, producer, 1);
}

static void _pin_read_stop (ByteProducer *self) {
  ArduinoUnoInputPinByteProducer *producer = (ArduinoUnoInputPinByteProducer *) self;
  rivulet_timer->clear_task (producer->_task_id);
}

ArduinoUnoInputPinByteProducer *arduino_uno_input_pin_byte_producer_create (Byte pin) {
  ArduinoUnoInputPinByteProducer *producer = xmalloc (sizeof (ArduinoUnoInputPinByteProducer));
  byte_producer_initialize ((ByteProducer *)producer, _pin_read_start, _pin_read_stop);
  producer->_pin = pin;
  return producer;
}
