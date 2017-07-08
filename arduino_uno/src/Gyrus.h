#ifndef GYRUS_ARDUINO_UNO_GYRUS_H
#define GYRUS_ARDUINO_UNO_GYRUS_H

#include "Sources.h"
#include "Sinks.h"
#include "GyrusUtils.h"

typedef Sinks *(*gyrus_application) (Sources *sources);

void gyrus_run(gyrus_application application);

#endif //GYRUS_ARDUINO_UNO_GYRUS_H
