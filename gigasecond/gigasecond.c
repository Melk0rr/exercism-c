#include "gigasecond.h"

#define GIGASECOND 1e9

void gigasecond(time_t input, char *output, size_t size)
{
  time_t new_time = input + GIGASECOND;
  strftime(output, size, "%F %T", gmtime(&new_time));
}
