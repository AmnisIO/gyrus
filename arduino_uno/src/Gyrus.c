#include "Gyrus.h"
#include <RivuletTimer.h>
#include <Arduino.h>
#include "DigitalWriteListener.h"
#include "AnalogWriteListener.h"

void gyrus_run (gyrus_application application) {
  Sources *sources = sources_create ();
  Sinks *sinks = application (sources);
  rivulet_timer_initialize (millis);
  if (sinks->D0 != NULL) sinks->D0->add_listener (sinks->D0, digital_write_listener_create (GYRUS_PIN_D0));
  if (sinks->D1 != NULL) sinks->D1->add_listener (sinks->D1, digital_write_listener_create (GYRUS_PIN_D1));
  if (sinks->D2 != NULL) sinks->D2->add_listener (sinks->D2, digital_write_listener_create (GYRUS_PIN_D2));
  if (sinks->D3 != NULL) sinks->D3->add_listener (sinks->D3, analog_write_listener_create (GYRUS_PIN_D3));
  if (sinks->D4 != NULL) sinks->D4->add_listener (sinks->D4, digital_write_listener_create (GYRUS_PIN_D4));
  if (sinks->D5 != NULL) sinks->D5->add_listener (sinks->D5, analog_write_listener_create (GYRUS_PIN_D5));
  if (sinks->D6 != NULL) sinks->D6->add_listener (sinks->D6, analog_write_listener_create (GYRUS_PIN_D6));
  if (sinks->D7 != NULL) sinks->D7->add_listener (sinks->D7, digital_write_listener_create (GYRUS_PIN_D7));
  if (sinks->D8 != NULL) sinks->D8->add_listener (sinks->D8, digital_write_listener_create (GYRUS_PIN_D8));
  if (sinks->D9 != NULL) sinks->D9->add_listener (sinks->D9, analog_write_listener_create (GYRUS_PIN_D9));
  if (sinks->D10 != NULL) sinks->D10->add_listener (sinks->D10, analog_write_listener_create (GYRUS_PIN_D10));
  if (sinks->D11 != NULL) sinks->D11->add_listener (sinks->D11, analog_write_listener_create (GYRUS_PIN_D11));
  if (sinks->D12 != NULL) sinks->D12->add_listener (sinks->D12, digital_write_listener_create (GYRUS_PIN_D12));
  if (sinks->D13 != NULL || sinks->LED != NULL) {
    RivuletListener *digital_write_listener_13 = digital_write_listener_create (GYRUS_PIN_D13);
    if (sinks->D13 != NULL) sinks->D13->add_listener (sinks->D13, digital_write_listener_13);
    if (sinks->LED != NULL) sinks->LED->add_listener (sinks->LED, digital_write_listener_13);
  }
  // TODO: Change to timer interrupts
  while (GYRUS_TRUE) {
    rivulet_timer->tick ();
  }
}