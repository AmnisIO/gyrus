#include <Arduino.h>
#include "Sources.h"
#include "DigitalReadProducer.h"
#include "AnalogReadProducer.h"

static const int D1 = 1;
static const int D2 = 2;
static const int D3 = 3;
static const int D4 = 4;
static const int D5 = 5;
static const int D6 = 6;
static const int D7 = 7;
static const int D8 = 8;
static const int D9 = 9;
static const int D10 = 10;
static const int D11 = 11;
static const int D12 = 12;
static const int D13 = 13;

Sources *sources_create () {
  Sources *sources = xmalloc (sizeof (Sources));
  sources->D1 = digital_read_stream_create (D1);
  sources->D2 = digital_read_stream_create (D2);
  sources->D3 = digital_read_stream_create (D3);
  sources->D4 = digital_read_stream_create (D4);
  sources->D5 = digital_read_stream_create (D5);
  sources->D6 = digital_read_stream_create (D6);
  sources->D7 = digital_read_stream_create (D7);
  sources->D8 = digital_read_stream_create (D8);
  sources->D9 = digital_read_stream_create (D9);
  sources->D10 = digital_read_stream_create (D10);
  sources->D11 = digital_read_stream_create (D11);
  sources->D12 = digital_read_stream_create (D12);
  sources->D13 = digital_read_stream_create (D13);
  sources->LED = sources->D13;
  sources->A0 = analog_read_stream_create (A0);
  sources->A1 = analog_read_stream_create (A1);
  sources->A2 = analog_read_stream_create (A2);
  sources->A3 = analog_read_stream_create (A3);
  sources->A4 = analog_read_stream_create (A4);
  sources->A5 = analog_read_stream_create (A5);
  return sources;
}
