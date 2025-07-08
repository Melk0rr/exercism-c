#include "scrabble_score.h"
#include <string.h>

static int const letter_values[] = {
    ['a'] = 1, ['b'] = 3,  ['c'] = 3, ['d'] = 2, ['e'] = 1,  ['f'] = 4,
    ['g'] = 2, ['h'] = 4,  ['i'] = 1, ['j'] = 8, ['k'] = 5,  ['l'] = 1,
    ['m'] = 3, ['n'] = 1,  ['o'] = 1, ['p'] = 3, ['q'] = 10, ['r'] = 1,
    ['s'] = 1, ['t'] = 1,  ['u'] = 1, ['v'] = 4, ['w'] = 4,  ['x'] = 8,
    ['y'] = 4, ['z'] = 10,
};

static char to_lower_case(char const ch)
{
  return (ch >= 'A' && ch <= 'Z') ? ch + 32 : ch;
}

unsigned int score(char const * const word)
{
  size_t score = 0;
  for (size_t i = 0; i < strlen(word); i++)
    score += letter_values[(int)to_lower_case(word[i])];

  return score;
}
