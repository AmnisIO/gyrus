#include <Arduino.h>
#include <unistd.h>
#include <RivuletTimer.h>
#include "ByteStream.h"
#include "DigitalReadProducer.h"

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
  rivulet_timer_initialize (millis);
  ByteStream *pin10$ = digital_read_stream_create (10);
  ByteListener *listener = byte_listener_create (_next, _error, _complete);
  pin10$->add_listener (pin10$, listener);
  for (int i = 0; i < 10; i++) {
    rivulet_timer->tick ();
    sleep (1);
  }
  return 0;
}