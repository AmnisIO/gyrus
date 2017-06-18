#include "GyrusTimer.h"

static GyrusTimer *timer = NULL;

static GyrusTaskIdentifier _set_timeout (gyrus_task_callback callback, void *argument, int delay) {
  GyrusTask *task = gyrus_task_create (callback, argument, GYRUS_TASK_TYPE_SINGLE, delay);
  timer->_tasks->push (timer->_tasks, task);
  return task->id;
}

static GyrusTaskIdentifier _set_interval (gyrus_task_callback callback, void *argument, int period) {
  GyrusTask *task = gyrus_task_create (callback, argument, GYRUS_TASK_TYPE_PERIODIC, period);
  timer->_tasks->push (timer->_tasks, task);
  return task->id;
}

static Boolean _find_by_id (void *left, void *right) {
  return ((GyrusTask *) left)->id == ((GyrusTask *) right)->id ? 1: 0;
}

static void _clear_timeout (GyrusTaskIdentifier id) {
  VariableLengthArray *tasks = timer->_tasks;
  GyrusTask *to_find = xmalloc (sizeof (GyrusTask));
  to_find->id = id;
  int index = tasks->find_index (tasks, (void *) to_find, _find_by_id);
  if (index == -1) return;
  tasks->remove (tasks, index);
}

static void _tick () {
  VariableLengthArray *tasks = timer->_tasks;
  int length = tasks->length (tasks);
  if (length == 0) return;
  Milliseconds current_time = timer->get_milliseconds ();
  for (int i = 0; i < length; i++) {
    GyrusTask *task = tasks->get (tasks, i);
    if (current_time < (task->last_called_at + task->period)) continue;
    task->last_called_at = current_time;
    task->callback (task->argument);
    if (task->type == GYRUS_TASK_TYPE_PERIODIC) continue;
    tasks->remove (tasks, i);
    i--;
  }
}

GyrusTimer *gyrus_timer_create (gyrus_timer_get_milliseconds get_milliseconds) {
  if (timer != NULL) return timer;
  timer = xmalloc (sizeof (GyrusTimer));
  timer->get_milliseconds = get_milliseconds;
  timer->set_timeout = _set_timeout;
  timer->set_interval = _set_interval;
  timer->clear_timeout = _clear_timeout;
  timer->tick = _tick;
  variable_length_array_initialize (&(timer->_tasks));
  return timer;
}
