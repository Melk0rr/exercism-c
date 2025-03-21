#include "binary_search.h"

const int *binary_search(int value, const int *arr, size_t length)
{
  size_t low = 0;
  size_t up = length;
  while (low < up)
  {
    unsigned int middle = (up + low) / 2;
    int element = arr[middle];

    if (element < value)
      low = middle + 1;

    else if (element > value)
      up = middle;

    else
      return &arr[middle];
  }

  return NULL;
}
