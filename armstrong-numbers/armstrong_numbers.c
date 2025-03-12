#include <math.h>
#include "armstrong_numbers.h"

int count_digits(int num)
{
  int count = 0;
  while (num != 0)
  {
    num /= 10;
    count++;
  }
  return count;
}

bool is_armstrong_number(int candidate)
{
  int original = candidate;
  int sum = 0;
  unsigned int n = count_digits(candidate);

  while (original != 0)
  {
    unsigned short int digit = original % 10;
    sum += pow(digit, n);
    original /= 10;
  }
  
  return candidate == sum;
}
