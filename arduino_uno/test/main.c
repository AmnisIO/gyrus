#include <Arduino.h>
#include <Sources.h>
#include <Sinks.h>
#include <Gyrus.h>

static Byte HIGH = 1;
static Byte LOW = 0;

Byte toggle(Byte value) {
  return value == HIGH ? LOW : HIGH;
}

Sinks* blink(Sources* arduino) {
  Sinks* sinks = sinks_create();
  ByteStream* sampler = byte_stream_periodic(500);
  ByteStream* sampledInput = sampler->sample(sampler, arduino->D12);
  sinks->LED = sampledInput->map(sampledInput, toggle);
  return sinks;
}

int main () {
  gyrus_run (blink);
}