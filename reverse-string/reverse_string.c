#include "reverse_string.h"
#include <stdlib.h>
#include <string.h>

char * reverse(char const * const value)
{
  size_t const value_len = strlen(value);
  char * const reversed = malloc((value_len + 1) * sizeof(char));

  if (!reversed)
    exit(EXIT_FAILURE);

  for (size_t i = 0; i < value_len; i++)
    reversed[i] = value[value_len - 1 - i];

  reversed[value_len] = '\0';
  return reversed;
}
