#include "isogram.h"

bool is_isogram(const char phrase[])
{
  if (!phrase)
    return false;

  bool seen[256] = {false};
  for (int i = 0; phrase[i] != '\0'; i++)
  {
    int letter = phrase[i];
    if (seen[letter] == true && (letter != 32 && letter != 45))
      return false;
  }
  return true;
}
