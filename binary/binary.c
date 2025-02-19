#include <string.h>
#include "binary.h"

int convert(const char *input)
{
  int count = 0;
  for (int i = 0; input[i]; i++)
  {
    unsigned short int bit = input[i] - '0';
    if (bit > 1)
      return INVALID;

    count += bit << (strlen(input) - i - 1);
  }
  return count;
}
