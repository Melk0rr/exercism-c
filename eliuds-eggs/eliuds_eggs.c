#include "eliuds_eggs.h"

int egg_count(int display)
{
  int count = 0;
  while (display != 0)
  {
    if (display & 1)
      count++;

    display >>= 1;
  }

  return count;
}
