#include "Sources.h"
#include "DigitalReadProducer.h"

static Byte D1 = 1;
static Byte D2 = 2;
static Byte D3 = 3;
static Byte D4 = 4;
static Byte D5 = 5;
static Byte D6 = 6;
static Byte D7 = 7;
static Byte D8 = 8;
static Byte D9 = 9;
static Byte D10 = 10;
static Byte D11 = 11;
static Byte D12 = 12;
static Byte D13 = 13;

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
  return sources;
}
