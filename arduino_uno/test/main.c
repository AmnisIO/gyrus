#include <Arduino.h>
#include <RivuletTimer.h>
#include <Sources.h>
#include <Sinks.h>
#include <DigitalWriteListener.h>
#include <unistd.h>

int main () {
  rivulet_timer_initialize (millis);
  Sources *sources = sources_create ();
  Sinks *sinks = sinks_create ();
  sinks->LED = sources->D10->map_to (sources->D10, 15);
  void *listener = digital_write_listener_create (13);
  sinks->LED->add_listener (sinks->LED, (ByteListener *) listener);
  for (int i = 0; i < 10; i++) {
    rivulet_timer->tick ();
    sleep (1);
  }
  return 0;
}