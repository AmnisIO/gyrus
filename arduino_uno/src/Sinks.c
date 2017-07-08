#include "Sinks.h"

Sinks *sinks_create () {
  Sinks *sinks = xmalloc (sizeof (Sinks));
  // TODO: Investigate
  // byte_stream_empty() and byte_stream_never() do not work, only NULL does
  sinks->D0 = rivulet_stream_never ();
  sinks->D1 = rivulet_stream_never ();
  sinks->D2 = rivulet_stream_never ();
  sinks->D3 = rivulet_stream_never ();
  sinks->D4 = rivulet_stream_never ();
  sinks->D5 = rivulet_stream_never ();
  sinks->D6 = rivulet_stream_never ();
  sinks->D7 = rivulet_stream_never ();
  sinks->D8 = rivulet_stream_never ();
  sinks->D9 = rivulet_stream_never ();
  sinks->D10 = rivulet_stream_never ();
  sinks->D11 = rivulet_stream_never ();
  sinks->D12 = rivulet_stream_never ();
  sinks->D13 = rivulet_stream_never ();
  sinks->LED = rivulet_stream_never ();
  return sinks;
}

