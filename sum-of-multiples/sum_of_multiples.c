#include "sum_of_multiples.h"

int *multiple(unsigned int factor, unsigned int limit)
{
  int *multipleArray;
  int mult = 0;
  for (unsigned int i = 1; mult < limit; i++)
  {
    mult = factor * i;
    multipleArray[i - 1] = mult;
  }
  return multipleArray;
}
unsigned int sum(const unsigned int *factors, const size_t number_of_factors, const unsigned int limit) {}
