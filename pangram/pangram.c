#include "pangram.h"
#include <stddef.h>
#include <stdint.h>

static char const to_lower_case(char const ch)
{
  return (ch >= 'A' && ch <= 'Z') ? ch + 32 : ch;
}

bool is_pangram(char const * const sentence)
{
  if (!sentence)
    return false;

  uint8_t letterCount[256] = {0};
  for (size_t i = 0; sentence[i] != '\0'; i++)
    letterCount[(int)to_lower_case(sentence[i])]++;

  size_t count = 0;
  for (size_t i = 97; i < 123; i++)
    if (letterCount[i] > 0)
      ++count;

  return count >= 26;
}
