#include "collatz_conjecture.h"

int steps(int start)
{
  if (start < 1)
    return ERROR_VALUE;

  int count = 0;
  for (; start > 1; count++)
    start = (start % 2) ? start * 3 + 1 : start / 2;

  return count;
}
