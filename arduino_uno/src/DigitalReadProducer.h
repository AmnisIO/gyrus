#ifndef GYRUS_ARDUINO_UNO_DIGITALREADPRODUCER_H
#define GYRUS_ARDUINO_UNO_DIGITALREADPRODUCER_H

#include "ByteProducer.h"
#include "RivuletTask.h"

typedef struct DigitalReadProducer {
  ByteObservableType type;
  byte_producer_internal_start _start;
  byte_producer_internal_stop _stop;
  byte_producer_start start;
  byte_producer_stop stop;
  Byte _pin;
  ByteListenerInternal *_listener;
  RivuletTaskIdentifier _task_id;
} DigitalReadProducer;

DigitalReadProducer *digital_read_producer_create (Byte pin);
ByteStream *digital_read_stream_create (Byte pin);

#endif //GYRUS_ARDUINO_UNO_DIGITALREADPRODUCER_H
