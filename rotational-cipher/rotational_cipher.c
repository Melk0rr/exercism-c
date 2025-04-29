#include "rotational_cipher.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *rotate(const char *text, int shift_key)
{
  unsigned int text_size = strlen(text);
  char *rotated = malloc((text_size + 1) * sizeof(char));

  // TODO: handle upper and lower case
  unsigned int i = 0;
  for (; i < text_size; i++)
  {
    rotated[i] = ((text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122))
                     ? (char)(((((int)text[i] - 97) + shift_key) % 26) + 97)
                     : text[i];
    printf("%d -> %d", text[i], rotated[i]);
  }

  rotated[i] = '\0';

  return rotated;
}
