#include "ArduinoUnoSources.h"
#include "ArduinoUnoInputPinByteProducer.h"

ArduinoUnoSources *arduino_uno_sources_create () {
  ArduinoUnoSources *sources = xmalloc (sizeof (ArduinoUnoSources));
  sources->D1$ = arduino_uno_input_pin_byte_stream_create (1);
  sources->D2$ = arduino_uno_input_pin_byte_stream_create (2);
  sources->D3$ = arduino_uno_input_pin_byte_stream_create (3);
  sources->D4$ = arduino_uno_input_pin_byte_stream_create (4);
  sources->D5$ = arduino_uno_input_pin_byte_stream_create (5);
  sources->D6$ = arduino_uno_input_pin_byte_stream_create (6);
  sources->D7$ = arduino_uno_input_pin_byte_stream_create (7);
  sources->D8$ = arduino_uno_input_pin_byte_stream_create (8);
  sources->D9$ = arduino_uno_input_pin_byte_stream_create (9);
  sources->D10$ = arduino_uno_input_pin_byte_stream_create (10);
  sources->D11$ = arduino_uno_input_pin_byte_stream_create (11);
  sources->D12$ = arduino_uno_input_pin_byte_stream_create (12);
  sources->D13$ = arduino_uno_input_pin_byte_stream_create (13);
  sources->LED$ = sources->D13$;
  return sources;
}
