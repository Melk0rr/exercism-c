#include "square_root.h"

unsigned int square_root(unsigned int num)
{
  if (num == 1)
    return num;

  unsigned int arr[num];
  for (unsigned int i = 0; i < num; i++)
    arr[i] = i + 1;

  unsigned int res, l = 0, r = num - 1;
  while (l <= r)
  {
    unsigned int m = l + ((r - l) / 2);
    res = arr[m];

    if ((res * res) < num)
      l = m + 1;
    else if ((res * res) > num)
      r = m - 1;
    else
      break;
  }

  return res;
}
