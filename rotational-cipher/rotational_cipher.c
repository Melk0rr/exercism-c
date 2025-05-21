#include "rotational_cipher.h"
#include <stdlib.h>
#include <string.h>

char rotate_letter(char letter, int shift, int modulo)
{
  return (char)(((((int)letter - modulo) + shift) % 26) + modulo);
}

char *rotate(const char *text, int shift_key)
{
  unsigned int text_size = strlen(text);
  char *rotated = malloc((text_size + 1) * sizeof(char));

  // TODO: handle upper and lower case
  unsigned int i = 0;
  for (; i < text_size; i++)
    rotated[i] = (text[i] >= 65 && text[i] <= 90)    ? rotate_letter(text[i], shift_key, 65)
                 : (text[i] >= 97 && text[i] <= 122) ? rotate_letter(text[i], shift_key, 97)
                                                     : text[i];

  rotated[i] = '\0';
  return rotated;
}
