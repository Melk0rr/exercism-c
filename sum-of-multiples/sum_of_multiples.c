#include "sum_of_multiples.h"
#include <stdlib.h>

unsigned int sum(unsigned int const * const factors,
                 size_t const number_of_factors, unsigned int const limit)
{
  size_t sum = 0;
  for (size_t i = 1; i < limit; i++)
  {
    for (size_t j = 0; j < number_of_factors; j++)
    {
      unsigned int const factor = factors[j];
      if (factor == 0)
        continue;

      if (i % factor == 0)
      {
        sum += i;
        break;
      }
    }
  }

  return sum;
}
