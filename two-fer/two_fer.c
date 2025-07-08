#include "two_fer.h"
#include <stdio.h>

void two_fer(char * const buffer, char const * const name)
{
  sprintf(buffer, "One for %s, one for me.", name ? name : "you");
}
