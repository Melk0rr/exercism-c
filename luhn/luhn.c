#include <string.h>

#include "luhn.h"

bool is_valid_char(char cc) { return (cc == 32) || (cc >= 48 && cc <= 57); }
int double_digit(int digit) { return (digit * 2 > 9) ? digit * 2 - 9 : digit * 2; }

bool luhn(const char *num)
{
  if (strlen(num) <= 1)
    return false;

  char doubled_num[strlen(num)];
  unsigned int non_digit_counter = 0;
  for (unsigned int i = 0; num[i] != '\0'; i++)
  {
    char digit = num[i] - '0';
    if (!is_valid_char(num[i]))
      return false;

    if (num[i] == 32)
      ++non_digit_counter;

    else if (i % 2 == 0 || (i - non_digit_counter) % 2 == 0)
      digit = double_digit(digit);

    doubled_num[i] = (char)(digit + '0');
  }

  return true;
}
