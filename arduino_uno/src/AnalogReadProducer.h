#ifndef GYRUS_ARDUINO_UNO_ANALOGREADPRODUCER_H
#define GYRUS_ARDUINO_UNO_ANALOGREADPRODUCER_H

#include <Rivulet.h>
#include "GyrusUtils.h"

typedef struct AnalogReadProducer {
  RivuletListenerType listener_type;
  RivuletProducerType producer_type;
  Pin _pin;
  RivuletListener *_listener;
  RivuletTaskIdentifier _task_id;
} AnalogReadProducer;

AnalogReadProducer *analog_read_producer_create (Pin pin);
RivuletStream *analog_read_stream_create (Pin pin);

#endif //GYRUS_ARDUINO_UNO_ANALOGREADPRODUCER_H
