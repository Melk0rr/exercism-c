#include "sieve.h"

uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes)
{
  if (limit < 2) return 0;
  if (limit == 2)
  {
    primes[0] = 2;
    return 1;
  }

  uint32_t count = 1;
  for (uint32_t i = 3; i <= limit && count < max_primes; i += 2) {
    unsigned char flag = 0;
    for (uint32_t j = 3; j * j <= i; j += 2) {
      if (i % j == 0)
      {
        flag = 1;
        break;
      }
    }

    if (!flag)
      primes[count++] = i;
  }

  return count;
}
