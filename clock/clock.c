#include "clock.h"
#include <stdio.h>
#include <string.h>

#define MIN_PER_DAY (24 * 60)

int str_to_int(char *str)
{
  int number;
  sscanf(str, "%d", &number);

  return number;
}

clock_t clock_create(int hour, int minute)
{
  int total_minutes = (((hour % 24) * 60 + minute) % MIN_PER_DAY + MIN_PER_DAY) % MIN_PER_DAY;
  clock_t new_clock;
  sprintf(new_clock.text, "%02d:%02d", total_minutes / 60, total_minutes % 60);

  return new_clock;
}

clock_t clock_add(clock_t clock, int minute_add) { return clock_create(str_to_int(clock.text), str_to_int(clock.text + 3) + minute_add); }
clock_t clock_subtract(clock_t clock, int minute_add) { return clock_create(str_to_int(clock.text), str_to_int(clock.text + 3) - minute_add); }
bool clock_is_equal(clock_t a, clock_t b) { return !strcmp(a.text, b.text); }
