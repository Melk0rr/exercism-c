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

mult_t merge_mult(mult_t *mults) {}

unsigned int sum(const unsigned int *factors, const size_t number_of_factors, const unsigned int limit)
{
  mult_t multiple_arrays[number_of_factors];
  unsigned int total_size = 0;

  for (unsigned int i = 0; i < number_of_factors; i++)
  {
    multiple_arrays[i] = multiple(factors[i], limit);
    total_size += multiple_arrays[i].size;
  }

  mult_t merged = merge_mult(multiple_arrays);
  unsigned int sum = 0;

  for (unsigned int i; i < merged.size; i++)
    sum += merged.array[i];

  return sum;
}
