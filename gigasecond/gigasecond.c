#include "gigasecond.h"

#define GIGASECOND 1e9

void gigasecond(time_t const input, char * const output, size_t const size)
{
  time_t const new_time = input + GIGASECOND;
  strftime(output, size, "%F %T", gmtime(&new_time));
}
