#ifndef GYRUS_ARDUINO_UNO_ANALOGREADPRODUCER_H
#define GYRUS_ARDUINO_UNO_ANALOGREADPRODUCER_H

#include <RivuletStream.h>
#include <RivuletTask.h>

typedef struct AnalogReadProducer {
  RivuletObservableType type;
  rivulet_producer_internal_start _start;
  rivulet_producer_internal_stop _stop;
  rivulet_producer_start start;
  rivulet_producer_stop stop;
  int _pin;
  RivuletListenerInternal *_listener;
  RivuletTaskIdentifier _task_id;
} AnalogReadProducer;

AnalogReadProducer *analog_read_producer_create (int pin);
RivuletStream *analog_read_stream_create (int pin);

#endif //GYRUS_ARDUINO_UNO_ANALOGREADPRODUCER_H
