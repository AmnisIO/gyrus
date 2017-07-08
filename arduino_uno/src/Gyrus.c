#include <RivuletTimer.h>
#include "Gyrus.h"
#include "DigitalWriteListener.h"
#include "AnalogWriteListener.h"

static const Pin D0 = 0;
static const Pin D1 = 1;
static const Pin D2 = 2;
static const Pin D3 = 3;
static const Pin D4 = 4;
static const Pin D5 = 5;
static const Pin D6 = 6;
static const Pin D7 = 7;
static const Pin D8 = 8;
static const Pin D9 = 9;
static const Pin D10 = 10;
static const Pin D11 = 11;
static const Pin D12 = 12;
static const Pin D13 = 13;

void gyrus_run (gyrus_application application) {
  Sources *sources = sources_create ();
  Sinks *sinks = application (sources);
  if (sinks == NULL) return;
  rivulet_timer_initialize (millis);
  // TODO: Investigate
  // int_stream_empty() and int_stream_never() do not work, only NULL does
  if (sinks->D0 != NULL) sinks->D0->add_listener (sinks->D0, digital_write_listener_create (D0));
  if (sinks->D1 != NULL) sinks->D1->add_listener (sinks->D1, digital_write_listener_create (D1));
  if (sinks->D2 != NULL) sinks->D2->add_listener (sinks->D2, digital_write_listener_create (D2));
  if (sinks->D3 != NULL) sinks->D3->add_listener (sinks->D3, analog_write_listener_create (D3));
  if (sinks->D4 != NULL) sinks->D4->add_listener (sinks->D4, digital_write_listener_create (D4));
  if (sinks->D5 != NULL) sinks->D5->add_listener (sinks->D5, analog_write_listener_create (D5));
  if (sinks->D6 != NULL) sinks->D6->add_listener (sinks->D6, analog_write_listener_create (D6));
  if (sinks->D7 != NULL) sinks->D7->add_listener (sinks->D7, digital_write_listener_create (D7));
  if (sinks->D8 != NULL) sinks->D8->add_listener (sinks->D8, digital_write_listener_create (D8));
  if (sinks->D9 != NULL) sinks->D9->add_listener (sinks->D9, analog_write_listener_create (D9));
  if (sinks->D10 != NULL) sinks->D10->add_listener (sinks->D10, analog_write_listener_create (D10));
  if (sinks->D11 != NULL) sinks->D11->add_listener (sinks->D11, analog_write_listener_create (D11));
  if (sinks->D12 != NULL) sinks->D12->add_listener (sinks->D12, digital_write_listener_create (D12));
  RivuletListener *digital_write_listener_D13 = digital_write_listener_create (D13);
  if (sinks->D13 != NULL) sinks->D13->add_listener (sinks->D13, digital_write_listener_D13);
  if (sinks->LED != NULL) sinks->LED->add_listener (sinks->LED, digital_write_listener_D13);
  // TODO: Change to timer interrupts
  for (;;) {
    rivulet_timer->tick ();
  }
}