#include "ByteStreamTimer.h"
#include "Arduino.h"
#include "ByteListernerManager.h"
#include "ArduinoUnoInputPinByteProducer.h"

static void _pin_read (void *self) {
  ArduinoUnoInputPinByteProducer *producer = self;
  byte_listener_internal_next next = byte_listener_internal_next_get (producer->listener);
  Byte value = (Byte) digitalRead (producer->pin);
  next (producer->listener, value);
}

static void _pin_read_start (ByteProducer *self, ByteListenerInternal *listener) {
  ArduinoUnoInputPinByteProducer *producer = (ArduinoUnoInputPinByteProducer *) self;
  producer->listener = listener;
  byte_stream_timer_set_timeout (_pin_read, producer, 1);
}

static void _pin_read_stop (ByteProducer *self) {

}

ArduinoUnoInputPinByteProducer *arduino_uno_input_pin_byte_pruoducer_create (Byte pin) {
  ArduinoUnoInputPinByteProducer *producer = xmalloc (sizeof (ArduinoUnoInputPinByteProducer));
  byte_producer_initialize (producer, _pin_read_start, _pin_read_stop);
  producer->pin = pin;
  return producer;
}
