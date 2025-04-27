#include "rotational_cipher.h"
#include <stdlib.h>
#include <string.h>

char *rotate(const char *text, int shift_key)
{
  unsigned int text_size = strlen(text);
  char *rotated = malloc(text_size * sizeof(char));

  // TODO: alphabet roll over
  for (unsigned int i = 0; i < text_size; i++)
    rotated[i] = (char)((int)text[i] + (shift_key % 26));

  return rotated;
}
