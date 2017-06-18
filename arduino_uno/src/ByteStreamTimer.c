#include "ByteStreamTimer.h"
#include "GyrusTimer.h"
#include "Arduino.h"

static GyrusTimer *timer = NULL;

ByteStreamTimerTaskIdentifier
byte_stream_timer_set_timeout (byte_stream_timer_task task, void *argument, int delay_in_milliseconds) {
  if (timer == NULL) timer = gyrus_timer_create (millis);
  return timer->set_timeout (task, argument, delay_in_milliseconds);
}

ByteStreamTimerTaskIdentifier
byte_stream_timer_set_interval (byte_stream_timer_task task, void *argument, int period_in_milliseconds) {
  if (timer == NULL) timer = gyrus_timer_create (millis);
  return timer->set_interval (task, argument, period_in_milliseconds);
}

void byte_stream_timer_clear_timeout (ByteStreamTimerTaskIdentifier task_id) {
  if (timer == NULL) return;
  timer->clear_timeout (task_id);
}