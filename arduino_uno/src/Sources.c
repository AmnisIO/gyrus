#include "Sources.h"
#include "DigitalReadProducer.h"

static const Byte D1 = 1;
static const Byte D2 = 2;
static const Byte D3 = 3;
static const Byte D4 = 4;
static const Byte D5 = 5;
static const Byte D6 = 6;
static const Byte D7 = 7;
static const Byte D8 = 8;
static const Byte D9 = 9;
static const Byte D10 = 10;
static const Byte D11 = 11;
static const Byte D12 = 12;
static const Byte D13 = 13;

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
