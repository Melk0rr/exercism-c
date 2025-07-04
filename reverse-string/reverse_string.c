#include "reverse_string.h"
#include <stdlib.h>
#include <string.h>

char *reverse(const char *value)
{
  unsigned int value_len = strlen(value);
  char *reversed = malloc((value_len + 1) * sizeof(char));

  if (!reversed)
    exit(EXIT_FAILURE);

  for (unsigned int i = 0; i < value_len; i++)
    reversed[i] = value[value_len - 1 - i];

  reversed[value_len] = '\0';
  return reversed;
}
