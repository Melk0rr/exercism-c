#include "square_root.h"

unsigned int square_root(unsigned int num)
{
  unsigned int arr[num / 2];
  for (unsigned int i = 0; i <= num / 2; i++)
    arr[i] = i + 1;

  unsigned int l = 0, r = (num - 1) / 2;
  while (l <= r)
  {
    unsigned int m = l + ((r - l) / 2);

    if ((arr[m] * arr[m]) < num)
      l = m + 1;
    else if ((arr[m] * arr[m]) > num)
      r = m - 1;
    else
      return arr[m];
  }

  return -1;
}
