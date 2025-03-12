#include <math.h>
#include "armstrong_numbers.h"

bool is_armstrong_number(int candidate)
{
  int sum = candidate;
  unsigned int n = floor(log10(candidate) + 1);

  while (candidate)
  {
    sum -= pow(candidate % 10, n);
    candidate /= 10;
  }
  
  return sum == 0;
}
