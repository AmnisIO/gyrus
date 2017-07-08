#ifndef GYRUS_ARDUINO_UNO_ANALOGREADPRODUCER_H
#define GYRUS_ARDUINO_UNO_ANALOGREADPRODUCER_H

#include <RivuletStream.h>
#include <RivuletTask.h>
#include "GyrusUtils.h"

typedef struct AnalogReadProducer {
  RivuletObservableType type;
  rivulet_producer_internal_start _start;
  rivulet_producer_internal_stop _stop;
  rivulet_producer_start start;
  rivulet_producer_stop stop;
  Pin _pin;
  RivuletListenerInternal *_listener;
  RivuletTaskIdentifier _task_id;
} AnalogReadProducer;

AnalogReadProducer *analog_read_producer_create (Pin pin);
RivuletStream *analog_read_stream_create (Pin pin);

#endif //GYRUS_ARDUINO_UNO_ANALOGREADPRODUCER_H
