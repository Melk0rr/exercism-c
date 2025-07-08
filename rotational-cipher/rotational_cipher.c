#include "rotational_cipher.h"
#include <stdlib.h>
#include <string.h>

static char rotate_letter(char const letter, int const shift, int const modulo)
{
  return (char)(((((int)letter - modulo) + shift) % 26) + modulo);
}

char * rotate(char const * const text, int const shift_key)
{
  size_t const text_size = strlen(text);
  char * const rotated = malloc((text_size + 1) * sizeof(char));

  size_t i = 0;
  for (; i < text_size; i++)
    rotated[i] = (text[i] >= 65 && text[i] <= 90)
                     ? rotate_letter(text[i], shift_key, 65)
                 : (text[i] >= 97 && text[i] <= 122)
                     ? rotate_letter(text[i], shift_key, 97)
                     : text[i];

  rotated[i] = '\0';
  return rotated;
}
