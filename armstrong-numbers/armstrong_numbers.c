#include "armstrong_numbers.h"
#include <math.h>
#include <stdint.h>

bool is_armstrong_number(int candidate)
{
  int sum = candidate;
  uint8_t const n = floor(log10(candidate) + 1);

  while (candidate)
  {
    sum -= pow(candidate % 10, n);
    candidate /= 10;
  }

  return sum == 0;
}
