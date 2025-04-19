#include "sum_of_multiples.h"

mult_t multiple(unsigned int factor, unsigned int limit)
{
  mult_t factor_mult;
  factor_mult.size = 0;
  int mult = 0;
  for (unsigned int i = 1; mult < limit; i++)
  {
    mult = factor * i;
    factor_mult.array[i - 1] = mult;
    factor_mult.size++;
  }
  return factor_mult;
}
unsigned int sum(const unsigned int *factors, const size_t number_of_factors, const unsigned int limit) {}
