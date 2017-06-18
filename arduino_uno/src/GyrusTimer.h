#ifndef GYRUS_ARDUINO_UNO_ARDUINOSIMPLETIMER_H
#define GYRUS_ARDUINO_UNO_ARDUINOSIMPLETIMER_H

#include <VariableLengthArray.h>
#include "GyrusTask.h"

typedef Milliseconds (*gyrus_timer_get_milliseconds) ();

typedef struct GyrusTimer {
  VariableLengthArray *_tasks;
  gyrus_timer_get_milliseconds get_milliseconds;
  TaskIdentifier (*set_timeout) (gyrus_task_callback callback, void *argument, int delay);
  TaskIdentifier (*set_interval) (gyrus_task_callback callback, void *argument, int period);
  void (*clear_timeout) (TaskIdentifier id);
  void (*tick) ();
} GyrusTimer;

GyrusTimer *gyrus_timer_create (gyrus_timer_get_milliseconds get_milliseconds);

#endif //GYRUS_ARDUINO_UNO_ARDUINOSIMPLETIMER_H
