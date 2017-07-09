#include <Arduino.h>
#include <Gyrus.h>


int brightness = 0;

int change = 5;

int getCurrentBrightness (int event) {
  brightness = brightness + change;
  if (brightness <= GYRUS_SIGNAL_LEVEL_LOW || brightness >= GYRUS_SIGNAL_LEVEL_HIGH) change = -change;
  return brightness;
}

int toggle (int value) {
  return value == GYRUS_SIGNAL_LEVEL_LOW ? GYRUS_SIGNAL_LEVEL_HIGH : GYRUS_SIGNAL_LEVEL_LOW;
}

Sinks *application (Sources *arduino) {
  Sinks *sinks = sinks_create ();
  RivuletStream *_typewriter_intermediary_1 = rivulet_stream_periodic (3);
  RivuletStream *_typewriter_intermediary_2 = rivulet_stream_periodic (1);
  sinks->D10 = rivulet_stream_map (_typewriter_intermediary_1, getCurrentBrightness);
  RivuletStream *_sampled = rivulet_stream_sample (_typewriter_intermediary_2, arduino->LED);
  sinks->LED = rivulet_stream_map (_sampled, toggle);
  return sinks;
}

int main () {
  gyrus_run (application);
}