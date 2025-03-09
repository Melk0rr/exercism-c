#include <stdio.h>
#include "pangram.h"

int toLowerCase(char ch)
{
  return (ch >= 'A' && ch <= 'Z') ? ch + 32 : ch;
}

bool is_pangram(const char *sentence) {
  if (!sentence) return false;

  unsigned int letterCount[] = {
      [97]  = 0, [98]  = 0, [99]  = 0, [100] = 0, [101] = 0, [102] = 0,
      [103] = 0, [104] = 0, [105] = 0, [106] = 0, [107] = 0, [108] = 0,
      [109] = 0, [110] = 0, [111] = 0, [112] = 0, [113] = 0, [114] = 0,
      [115] = 0, [116] = 0, [117] = 0, [118] = 0, [119] = 0, [120] = 0,
      [121] = 0, [122] = 0
  };

  for (int i = 0; sentence[i] != '\0'; i++)
    letterCount[toLowerCase(sentence[i])]++;

  unsigned int count = 0;
  for (int i = 97; i < 123; i++)
    if (letterCount[i] > 0) ++count;

  return count >= 26;
}
