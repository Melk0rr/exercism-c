#include "hamming.h"
#include <string.h>

int compute(char const * const lhs, char const * const rhs)
{
  size_t const lhs_len = strlen(lhs), rhs_len = strlen(rhs);
  if (lhs_len != rhs_len)
    return -1;

  size_t ham_dist = 0;
  for (size_t i = 0; i < lhs_len; i++)
    if (lhs[i] != rhs[i])
      ++ham_dist;

  return ham_dist;
}
