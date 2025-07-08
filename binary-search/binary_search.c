#include "binary_search.h"

int const * binary_search(int const value, int const * const arr,
                          size_t const length)
{
  size_t low = 0;
  size_t up = length;
  while (low < up)
  {
    size_t const middle = (up + low) / 2;
    int const element = arr[middle];

    if (element < value)
      low = middle + 1;

    else if (element > value)
      up = middle;

    else
      return &arr[middle];
  }

  return NULL;
}
