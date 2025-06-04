#include "prime_factors.h"

size_t find_factors(uint64_t n, uint64_t factors[static MAXFACTORS])
{
  size_t number_of_factors = 0, div = 2;
  while (n > 1) {
    if (n % div)
      div++;

    else {
      factors[number_of_factors++] = div;
      n /= div;
    }
  }

  return number_of_factors;
}
