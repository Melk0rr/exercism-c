#include "sieve.h"

uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes)
{
  uint32_t count = 0;
  for (uint32_t i = 2; i <= limit && count < max_primes; i++) {
    unsigned char flag = 0;
    for (uint32_t j = 2; j <= i / 2; j++) {
      if (i % j == 0)
      {
        flag = 1;
        break;
      }
    }

    if (flag == 0)
      primes[count++] = i;
  }

  return count;
}
