#include "Sources.h"
#include "DigitalReadProducer.h"

Sources *sources_create () {
  Sources *sources = xmalloc (sizeof (Sources));
  sources->D1$ = digital_read_stream_create (1);
  sources->D2$ = digital_read_stream_create (2);
  sources->D3$ = digital_read_stream_create (3);
  sources->D4$ = digital_read_stream_create (4);
  sources->D5$ = digital_read_stream_create (5);
  sources->D6$ = digital_read_stream_create (6);
  sources->D7$ = digital_read_stream_create (7);
  sources->D8$ = digital_read_stream_create (8);
  sources->D9$ = digital_read_stream_create (9);
  sources->D10$ = digital_read_stream_create (10);
  sources->D11$ = digital_read_stream_create (11);
  sources->D12$ = digital_read_stream_create (12);
  sources->D13$ = digital_read_stream_create (13);
  sources->LED$ = sources->D13$;
  return sources;
}
