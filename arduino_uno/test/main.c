#include <Arduino.h>
#include "GyrusTimer.h"
#include "ByteStream.h"
#include "ArduinoUnoInputPinByteProducer.h"

void _next (ByteListener *self, Byte v) {
  printf ("%d\n", v);
}
void _error (ByteListener *self, int error) {
  printf ("%d\n", error);
}
void _complete (ByteListener *self) {
  printf ("completed\n");
}

int main () {
  ArduinoUnoInputPinByteProducer *producer = arduino_uno_input_pin_byte_producer_create (10);
  ByteStream *pin10$ = byte_stream_create ((ByteProducer *) producer);
  ByteListener *listener = byte_listener_create (_next, _error, _complete);
  GyrusTimer *timer = gyrus_timer_create (millis);
  pin10$->add_listener (pin10$, listener);
  for (int i = 0; i < 10; i++) {
    timer->tick ();
  }
  return 0;
}