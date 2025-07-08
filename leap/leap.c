#include "leap.h"
#include <stdbool.h>

bool leap_year(int const year)
{
  return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}
