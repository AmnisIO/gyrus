#include <Arduino.h>
#include <Gyrus.h>

Byte toggle (Byte value) {
  return value == HIGH ? LOW : HIGH;
}

Sinks *blink (Sources *arduino) {
  Sinks *sinks = sinks_create ();
  ByteStream *every_second = byte_stream_periodic (1);
  ByteStream* sampled_switch = every_second->sample(every_second, arduino->D2);
  sinks->LED = sampled_switch->map (sampled_switch, toggle);
  return sinks;
}

int main () {
  gyrus_run (blink);
}