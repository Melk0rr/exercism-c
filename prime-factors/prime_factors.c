#include "prime_factors.h"

size_t find_factors(uint64_t n, uint64_t factors[static MAXFACTORS])
{
  size_t number_of_factors = 0;
  for (unsigned int i = 2; i < MAXFACTORS; i++)
    while (n % i == 0) {
      n /= i;
      factors[number_of_factors++] = i;
    }

  return number_of_factors;
}
