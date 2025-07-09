#include "sieve.h"
#include <stdbool.h>

uint32_t sieve(uint32_t const limit, uint32_t * const primes,
               size_t const max_primes)
{
  if (limit < 2)
    return 0;

  if (limit == 2)
  {
    primes[0] = 2;
    return 1;
  }

  size_t count = 1;
  for (size_t i = 3; i <= limit && count < max_primes; i += 2)
  {
    bool flag = false;
    for (size_t j = 3; j * j <= i; j += 2)
    {
      if (i % j == 0)
      {
        flag = true;
        break;
      }
    }

    if (!flag)
      primes[count++] = i;
  }

  return count;
}
