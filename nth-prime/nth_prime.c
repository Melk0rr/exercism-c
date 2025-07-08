#include "nth_prime.h"
#include <stddef.h>

uint32_t nth(uint32_t const n)
{
  if (n == 0) return 0;
  if (n == 1) return 2;

  uint32_t nth = 2;
  size_t count = 1;
  for (size_t i = 3; count < n; i += 2)
  {
    unsigned char flag = 0;
    for (size_t j = 3; j * j <= i; j+= 2)
      if (i % j == 0)
      {
        flag = 1;
        break;
      }

    if (!flag)
    {
      nth = i;
      count++;
    }
  }

  return nth;
}
