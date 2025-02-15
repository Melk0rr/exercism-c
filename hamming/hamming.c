#include "hamming.h"
#include <string.h>

int compute(const char *lhs, const char *rhs)
{
  if (strlen(lhs) != strlen(rhs))
    return -1;

  int ham_dist = 0;

  for (unsigned int i = 0; i < strlen(lhs); i++)
    if (lhs[i] != rhs[i])
      ++ham_dist;

  return ham_dist;
}

