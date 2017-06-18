#ifndef GYRUS_ARDUINO_UNO_ARDUINOBYTEPRODUCER_H
#define GYRUS_ARDUINO_UNO_ARDUINOBYTEPRODUCER_H

#include "ByteProducer.h"
#include "GyrusTask.h"

typedef struct ArduinoUnoInputPinByteProducer {
  ByteObservableType type;
  byte_producer_internal_start _start;
  byte_producer_internal_stop _stop;
  byte_producer_start start;
  byte_producer_stop stop;
  Byte _pin;
  ByteListenerInternal *_listener;
  GyrusTaskIdentifier _task_id;
} ArduinoUnoInputPinByteProducer;

ArduinoUnoInputPinByteProducer *arduino_uno_input_pin_byte_producer_create(Byte pin);

#endif //GYRUS_ARDUINO_UNO_ARDUINOBYTEPRODUCER_H
