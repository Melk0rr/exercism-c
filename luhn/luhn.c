#include "luhn.h"
#include <string.h>

static bool is_valid_char(char const cc)
{
  return (cc == 32) || (cc >= 48 && cc <= 57);
}
static int double_digit(int const digit)
{
  return (digit * 2 > 9) ? digit * 2 - 9 : digit * 2;
}

bool luhn(char const * const num)
{
  size_t const num_len = strlen(num);
  if (num_len <= 1)
    return false;

  char doubled_num[num_len];
  size_t sum = 0;
  size_t digit_counter = 0;
  for (int i = num_len - 1; i >= 0; i--)
  {
    if (!is_valid_char(num[i]))
      return false;

    doubled_num[i] = num[i];
    if (num[i] != 32)
    {
      unsigned int doubled = num[i] - '0';
      if (++digit_counter % 2 == 0)
        doubled = double_digit(doubled);

      doubled_num[i] = (char)(doubled + '0');
      sum += doubled_num[i] - '0';
    }
  }

  return (digit_counter > 1) && (sum % 10 == 0);
}
