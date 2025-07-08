#include <stdint.h>
#include <string.h>
#include "binary.h"

int convert(char const * const input)
{
  int count = 0;
  for (int i = 0; input[i]; i++)
  {
    uint8_t const bit = input[i] - '0';
    if (bit > 1)
      return INVALID;

    count += bit << (strlen(input) - i - 1);
  }
  return count;
}
