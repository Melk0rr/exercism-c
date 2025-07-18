#include "difference_of_squares.h"

unsigned int sum_of_squares(unsigned int const number)
{
  return number * (number + 1) * (2 * number + 1) / 6;
}

unsigned int square_of_sum(unsigned int const number)
{
  return number * number * (number + 1) * (number + 1) / 4;
}

unsigned int difference_of_squares(unsigned int const number)
{
  return square_of_sum(number) - sum_of_squares(number);
}
