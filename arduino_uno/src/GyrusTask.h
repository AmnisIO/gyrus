#ifndef GYRUS_ARDUINO_UNO_GYRUSTASKARDUINO_H
#define GYRUS_ARDUINO_UNO_GYRUSTASKARDUINO_H

typedef enum GyrusTaskType {
  GYRUS_TASK_TYPE_NONE,
  GYRUS_TASK_TYPE_SINGLE,
  GYRUS_TASK_TYPE_PERIODIC
} GyrusTaskType;

typedef unsigned long Milliseconds;
typedef int GyrusTaskIdentifier;
typedef void (*gyrus_task_callback)(void *argument);

typedef struct GyrusTask {
  GyrusTaskIdentifier id;
  GyrusTaskType type;
  gyrus_task_callback callback;
  void *argument;
  Milliseconds last_called_at;
  int period;
} GyrusTask;

GyrusTask *gyrus_task_create(gyrus_task_callback callback, void* argument, GyrusTaskType type, int period);

#endif //GYRUS_ARDUINO_UNO_GYRUSTASKARDUINO_H
