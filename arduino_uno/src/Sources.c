#include <Arduino.h>
#include "Sources.h"
#include "DigitalReadProducer.h"
#include "AnalogReadProducer.h"

Sources *sources_create () {
  Sources *sources = xmalloc (sizeof (Sources));
  sources->D0 = digital_read_stream_create (GYRUS_PIN_D0);
  sources->D1 = digital_read_stream_create (GYRUS_PIN_D1);
  sources->D2 = digital_read_stream_create (GYRUS_PIN_D2);
  sources->D3 = digital_read_stream_create (GYRUS_PIN_D3);
  sources->D4 = digital_read_stream_create (GYRUS_PIN_D4);
  sources->D5 = digital_read_stream_create (GYRUS_PIN_D5);
  sources->D6 = digital_read_stream_create (GYRUS_PIN_D6);
  sources->D7 = digital_read_stream_create (GYRUS_PIN_D7);
  sources->D8 = digital_read_stream_create (GYRUS_PIN_D8);
  sources->D9 = digital_read_stream_create (GYRUS_PIN_D9);
  sources->D10 = digital_read_stream_create (GYRUS_PIN_D10);
  sources->D11 = digital_read_stream_create (GYRUS_PIN_D11);
  sources->D12 = digital_read_stream_create (GYRUS_PIN_D12);
  sources->D13 = digital_read_stream_create (GYRUS_PIN_D13);
  sources->LED = sources->D13;
  sources->A0 = analog_read_stream_create (GYRUS_PIN_A0);
  sources->A1 = analog_read_stream_create (GYRUS_PIN_A1);
  sources->A2 = analog_read_stream_create (GYRUS_PIN_A2);
  sources->A3 = analog_read_stream_create (GYRUS_PIN_A3);
  sources->A4 = analog_read_stream_create (GYRUS_PIN_A4);
  sources->A5 = analog_read_stream_create (GYRUS_PIN_A5);
  sources->A6 = analog_read_stream_create (GYRUS_PIN_A6);
  sources->A7 = analog_read_stream_create (GYRUS_PIN_A7);
  return sources;
}
