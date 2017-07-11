#include <Arduino.h>
#include <Gyrus.h>

int from_0_to_5 (int prev, int current) {
  return prev == 5 ? 0 : prev + 1;
}

int from_0_to_3_to_2 (int value) {
  int x = value % 3;
  int y = value % (6);
  return y > x ? (3 - x) : x;
}

int multiply_by_5 (int value) {
  return value * 5;
}

int toggle (int value) {
  return value == GYRUS_SIGNAL_LEVEL_LOW ? GYRUS_SIGNAL_LEVEL_HIGH : GYRUS_SIGNAL_LEVEL_LOW;
}

Sinks *application (Sources *arduino) {
  Sinks *sinks = sinks_create ();
  RivuletStream *_typewriter_intermediary_1 = rivulet_stream_periodic (1);
  RivuletStream *_typewriter_intermediary_2 = rivulet_stream_fold (_typewriter_intermediary_1, from_0_to_5, 0);
  RivuletStream *_typewriter_intermediary_3 = rivulet_stream_map (_typewriter_intermediary_2, from_0_to_3_to_2);
  RivuletStream *_typewriter_intermediary_4 = rivulet_stream_periodic (1);
  sinks->D10 = rivulet_stream_map (_typewriter_intermediary_3, multiply_by_5);
  RivuletStream *_sampled = rivulet_stream_sample (_typewriter_intermediary_4, arduino->LED);
  sinks->LED = rivulet_stream_map (_sampled, toggle);
  return sinks;
}

int main () {
  gyrus_run (application);
}