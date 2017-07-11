#ifndef GYRUS_ARDUINO_UNO_DIGITALREADPRODUCER_H
#define GYRUS_ARDUINO_UNO_DIGITALREADPRODUCER_H

#include "Rivulet.h"
#include "GyrusUtils.h"

typedef struct DigitalReadProducer {
  RivuletListenerType listener_type;
  RivuletProducerType producer_type;
  Pin _pin;
  RivuletListener *_listener;
  RivuletTaskIdentifier _task_id;
} DigitalReadProducer;

DigitalReadProducer *digital_read_producer_create (Pin pin);
RivuletStream *digital_read_stream_create (Pin pin);

#endif //GYRUS_ARDUINO_UNO_DIGITALREADPRODUCER_H
