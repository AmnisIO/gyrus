#include "Sinks.h"

Sinks *sinks_create () {
  Sinks *sinks = xmalloc (sizeof (Sinks));
  sinks->D0 = NULL;
  sinks->D1 = NULL;
  sinks->D2 = NULL;
  sinks->D3 = NULL;
  sinks->D4 = NULL;
  sinks->D5 = NULL;
  sinks->D6 = NULL;
  sinks->D7 = NULL;
  sinks->D8 = NULL;
  sinks->D9 = NULL;
  sinks->D10 = NULL;
  sinks->D11 = NULL;
  sinks->D12 = NULL;
  sinks->D13 = NULL;
  sinks->LED = NULL;
  return sinks;
}

