#include <RivuletTimer.h>
#include "Gyrus.h"
#include "DigitalWriteListener.h"
#include "Arduino.h"

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
static Byte LED = 13;
static Byte TRUE = 1;

void gyrus_run (gyrus_application application) {
  Sources *sources = sources_create ();
  Sinks *sinks = application (sources);
  if (sinks == NULL) return;
  sinks->D1$->add_listener (sinks->D1$, digital_write_listener_create (D1));
  sinks->D2$->add_listener (sinks->D2$, digital_write_listener_create (D2));
  sinks->D3$->add_listener (sinks->D3$, digital_write_listener_create (D3));
  sinks->D4$->add_listener (sinks->D4$, digital_write_listener_create (D4));
  sinks->D5$->add_listener (sinks->D5$, digital_write_listener_create (D5));
  sinks->D6$->add_listener (sinks->D6$, digital_write_listener_create (D6));
  sinks->D7$->add_listener (sinks->D7$, digital_write_listener_create (D7));
  sinks->D8$->add_listener (sinks->D8$, digital_write_listener_create (D8));
  sinks->D9$->add_listener (sinks->D9$, digital_write_listener_create (D9));
  sinks->D10$->add_listener (sinks->D10$, digital_write_listener_create (D10));
  sinks->D11$->add_listener (sinks->D11$, digital_write_listener_create (D11));
  sinks->D12$->add_listener (sinks->D12$, digital_write_listener_create (D12));
  sinks->D13$->add_listener (sinks->D13$, digital_write_listener_create (D13));
  sinks->LED$->add_listener (sinks->LED$, digital_write_listener_create (LED));
  // TODO: Change to timer interrupts
  rivulet_timer_initialize (millis);
  while (TRUE) {
    rivulet_timer->tick ();
  }
}