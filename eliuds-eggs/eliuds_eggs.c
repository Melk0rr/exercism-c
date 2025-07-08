#include "eliuds_eggs.h"
#include <stddef.h>

int egg_count(int display)
{
  size_t count = 0;
  while (display != 0)
  {
    if (display & 1)
      count++;

    display >>= 1;
  }

  return count;
}
