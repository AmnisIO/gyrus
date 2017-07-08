#include "Gyrus.h"
#include <RivuletTimer.h>
#include <Arduino.h>
#include "DigitalWriteListener.h"
#include "AnalogWriteListener.h"

void gyrus_run (gyrus_application application) {
  Sources *sources = sources_create ();
  Sinks *sinks = application (sources);
  rivulet_timer_initialize (millis);
  // TODO: Investigate
  // int_stream_empty() and int_stream_never() do not work, only NULL does
  sinks->D0->add_listener (sinks->D0, digital_write_listener_create (GYRUS_PIN_D0));
  sinks->D1->add_listener (sinks->D1, digital_write_listener_create (GYRUS_PIN_D1));
  sinks->D2->add_listener (sinks->D2, digital_write_listener_create (GYRUS_PIN_D2));
  sinks->D3->add_listener (sinks->D3, analog_write_listener_create (GYRUS_PIN_D3));
  sinks->D4->add_listener (sinks->D4, digital_write_listener_create (GYRUS_PIN_D4));
  sinks->D5->add_listener (sinks->D5, analog_write_listener_create (GYRUS_PIN_D5));
  sinks->D6->add_listener (sinks->D6, analog_write_listener_create (GYRUS_PIN_D6));
  sinks->D7->add_listener (sinks->D7, digital_write_listener_create (GYRUS_PIN_D7));
  sinks->D8->add_listener (sinks->D8, digital_write_listener_create (GYRUS_PIN_D8));
  sinks->D9->add_listener (sinks->D9, analog_write_listener_create (GYRUS_PIN_D9));
  sinks->D10->add_listener (sinks->D10, analog_write_listener_create (GYRUS_PIN_D10));
  sinks->D11->add_listener (sinks->D11, analog_write_listener_create (GYRUS_PIN_D11));
  sinks->D12->add_listener (sinks->D12, digital_write_listener_create (GYRUS_PIN_D12));
  sinks->D13->add_listener (sinks->D13, digital_write_listener_create (GYRUS_PIN_D13));
  sinks->LED->add_listener (sinks->LED, digital_write_listener_create (GYRUS_PIN_LED));
  // TODO: Change to timer interrupts
  while (GYRUS_TRUE) {
    rivulet_timer->tick ();
  }
}