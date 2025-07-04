#include "pangram.h"

static char to_lower_case(char ch) { return (ch >= 'A' && ch <= 'Z') ? ch + 32 : ch; }

bool is_pangram(const char *sentence)
{
  if (!sentence)
    return false;

  unsigned int letterCount[256] = {0};
  for (int i = 0; sentence[i] != '\0'; i++)
    letterCount[(int)to_lower_case(sentence[i])]++;

  unsigned int count = 0;
  for (int i = 97; i < 123; i++)
    if (letterCount[i] > 0)
      ++count;

  return count >= 26;
}
