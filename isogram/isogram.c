#include "isogram.h"

int toLowerCase(int ch)
{
  return (ch >= 'A' && ch <= 'Z') ? ch + 32 : ch;
}

bool is_isogram(const char phrase[])
{
  if (!phrase)
    return false;

  bool seen[256] = {false};
  for (int i = 0; phrase[i] != '\0'; i++)
  {
    int letter = toLowerCase(phrase[i]);
    if (seen[letter] == true && (letter != 32 && letter != 45))
      return false;

    else
       seen[letter] = true;
  }
  return true;
}
