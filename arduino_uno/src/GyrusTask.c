#include <utils.h>
#include "GyrusTask.h"

static int task_id_counter = 0;

GyrusTask *gyrus_task_create (gyrus_task_callback callback, void *argument, GyrusTaskType type, int period) {
  GyrusTask *task = xmalloc (sizeof (GyrusTask));
  task->callback = callback;
  task->argument = argument;
  task->type = type;
  task->id = task_id_counter++;
  task->period = period;
  task->last_called_at = (Milliseconds) 0;
}