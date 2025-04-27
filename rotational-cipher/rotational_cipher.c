#include "rotational_cipher.h"
#include <stdlib.h>
#include <string.h>

char *rotate(const char *text, int shift_key)
{
  unsigned int text_size = strlen(text);
  char *rotated = malloc(text_size * sizeof(char));

  // TODO: handle upper and lower case
  for (unsigned int i = 0; i < text_size; i++)
    rotated[i] = (char)(((((int)text[i] - 61) + shift_key) % 26) + 61);

  return rotated;
}
