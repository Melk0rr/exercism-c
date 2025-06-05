#include "nth_prime.h"

uint32_t nth(uint32_t n)
{
  if (n == 1)
    return 2;

  uint32_t nth = 0, count = 0;
  for (uint32_t i = 2; count < n; i++)
  {
    unsigned char flag = 0;
    if (!(i % 2) && i != 2)
      continue;

    for (uint32_t j = 3; j <= i / 2; j++)
      if (!(i % j))
      {
        flag = 1;
        break;
      }

    if (!flag)
    {
      count++;
      nth = i;
    }
  }

  return nth;
}
