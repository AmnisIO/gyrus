#ifndef GYRUS_ARDUINO_UNO_DIGITALREADPRODUCER_H
#define GYRUS_ARDUINO_UNO_DIGITALREADPRODUCER_H

#include "RivuletProducer.h"
#include "RivuletTask.h"
#include "GyrusUtils.h"

typedef struct DigitalReadProducer {
  RivuletObservableType type;
  rivulet_producer_internal_start _start;
  rivulet_producer_internal_stop _stop;
  rivulet_producer_start start;
  rivulet_producer_stop stop;
  Pin _pin;
  RivuletListenerInternal *_listener;
  RivuletTaskIdentifier _task_id;
} DigitalReadProducer;

DigitalReadProducer *digital_read_producer_create (Pin pin);
RivuletStream *digital_read_stream_create (Pin pin);

#endif //GYRUS_ARDUINO_UNO_DIGITALREADPRODUCER_H
