#include "ArduinoUnoSinks.h"

ArduinoUnoSinks *arduino_uno_sinks_create () {
  ArduinoUnoSinks *sinks = xmalloc (sizeof (ArduinoUnoSinks));
  sinks->D1$ = byte_stream_empty ();
  sinks->D2$ = byte_stream_empty ();
  sinks->D3$ = byte_stream_empty ();
  sinks->D4$ = byte_stream_empty ();
  sinks->D5$ = byte_stream_empty ();
  sinks->D6$ = byte_stream_empty ();
  sinks->D7$ = byte_stream_empty ();
  sinks->D8$ = byte_stream_empty ();
  sinks->D9$ = byte_stream_empty ();
  sinks->D10$ = byte_stream_empty ();
  sinks->D11$ = byte_stream_empty ();
  sinks->D12$ = byte_stream_empty ();
  sinks->D13$ = byte_stream_empty ();
  sinks->LED$ = sinks->D13$;
  return sinks;
}

