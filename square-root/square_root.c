#include "square_root.h"

unsigned int square_root(unsigned int const num)
{
  unsigned int arr[num / 2];
  for (unsigned int i = 0; i <= num / 2; i++)
    arr[i] = i + 1;

  unsigned int left = 0, right = (num - 1) / 2;
  while (left <= right)
  {
    unsigned int const middle = left + ((right - left) / 2);
    if ((arr[middle] * arr[middle]) < num)
      left = middle + 1;

    else if ((arr[middle] * arr[middle]) > num)
      right = middle - 1;

    else
      return arr[middle];
  }

  return -1;
}
