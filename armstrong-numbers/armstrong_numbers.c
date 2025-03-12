#include <math.h>
#include "armstrong_numbers.h"

bool is_armstrong_number(int candidate)
{
  int original = candidate;
  int sum = 0;
  unsigned int n = floor(log10(candidate) + 1);

  while (original != 0)
  {
    sum += pow(original % 10, n);
    original /= 10;
  }
  
  return candidate == sum;
}
