#ifndef CLOCK_H
#define CLOCK_H

#include <stdbool.h>

#define MAX_STR_LEN sizeof("##:##")

typedef struct clock_t
{
  char text[MAX_STR_LEN];
} clock_t;

clock_t clock_create(int const hour, int const minute);
clock_t clock_add(clock_t clock, int const minute_add);
clock_t clock_subtract(clock_t clock, int const minute_subtract);
bool clock_is_equal(clock_t const a, clock_t const b);

#endif
