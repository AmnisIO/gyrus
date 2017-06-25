#include <RivuletTimer.h>
#include "Gyrus.h"
#include "DigitalWriteListener.h"
#include "Arduino.h"

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
static const Byte LED = 13;
static const Byte TRUE = 1;

void gyrus_run (gyrus_application application) {
  Sources *sources = sources_create ();
  Sinks *sinks = application (sources);
  if (sinks == NULL) return;
  sinks->D1->add_listener (sinks->D1, digital_write_listener_create (D1));
  sinks->D2->add_listener (sinks->D2, digital_write_listener_create (D2));
  sinks->D3->add_listener (sinks->D3, digital_write_listener_create (D3));
  sinks->D4->add_listener (sinks->D4, digital_write_listener_create (D4));
  sinks->D5->add_listener (sinks->D5, digital_write_listener_create (D5));
  sinks->D6->add_listener (sinks->D6, digital_write_listener_create (D6));
  sinks->D7->add_listener (sinks->D7, digital_write_listener_create (D7));
  sinks->D8->add_listener (sinks->D8, digital_write_listener_create (D8));
  sinks->D9->add_listener (sinks->D9, digital_write_listener_create (D9));
  sinks->D10->add_listener (sinks->D10, digital_write_listener_create (D10));
  sinks->D11->add_listener (sinks->D11, digital_write_listener_create (D11));
  sinks->D12->add_listener (sinks->D12, digital_write_listener_create (D12));
  sinks->D13->add_listener (sinks->D13, digital_write_listener_create (D13));
  sinks->LED->add_listener (sinks->LED, digital_write_listener_create (LED));
  // TODO: Change to timer interrupts
  rivulet_timer_initialize (millis);
  while (TRUE) {
    rivulet_timer->tick ();
  }
}