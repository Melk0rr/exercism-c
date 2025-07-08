#include "isogram.h"
#include <stddef.h>

static char to_lower_case(char const ch)
{
  return (ch >= 'A' && ch <= 'Z') ? ch + 32 : ch;
}

bool is_isogram(char const phrase[])
{
  if (!phrase)
    return false;

  bool seen[256] = {false};
  for (size_t i = 0; phrase[i] != '\0'; i++)
  {
    char const letter = to_lower_case(phrase[i]);
    if (seen[(int)letter] == true && (letter != 32 && letter != 45))
      return false;

    else
      seen[(int)letter] = true;
  }
  return true;
}
