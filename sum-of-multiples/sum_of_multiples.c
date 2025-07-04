#include "sum_of_multiples.h"
#include <stdlib.h>

unsigned int sum(const unsigned int *factors, const size_t number_of_factors, const unsigned int limit)
{
  unsigned int sum = 0;
  for (unsigned int i = 1; i < limit; i++)
  {
    for (unsigned int j = 0; j < number_of_factors; j++)
    {
      unsigned int factor = factors[j];
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
