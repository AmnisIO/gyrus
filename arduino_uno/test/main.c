#include <Arduino.h>
#include <Gyrus.h>

int toggle (int value) {
  return value == HIGH ? LOW : HIGH;
}

Sinks *blink (Sources *arduino) {
  Sinks *sinks = sinks_create ();
  RivuletStream *every_second = rivulet_stream_periodic (1);
  RivuletStream* sampled_switch = every_second->sample(every_second, arduino->D2);
  sinks->LED = sampled_switch->map (sampled_switch, toggle);
  return sinks;
}

int main () {
  gyrus_run (blink);
}