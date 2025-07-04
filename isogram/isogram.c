#include "isogram.h"

static char to_lower_case(char ch) { return (ch >= 'A' && ch <= 'Z') ? ch + 32 : ch; }

bool is_isogram(const char phrase[])
{
  if (!phrase)
    return false;

  bool seen[256] = {false};
  for (int i = 0; phrase[i] != '\0'; i++)
  {
    int letter = to_lower_case(phrase[i]);
    if (seen[letter] == true && (letter != 32 && letter != 45))
      return false;

    else
      seen[letter] = true;
  }
  return true;
}
