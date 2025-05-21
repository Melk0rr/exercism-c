#ifndef ROTATIONAL_CIPHER_H
#define ROTATIONAL_CIPHER_H

#include <stdbool.h>

char rotate_letter(char letter, int shift, int modulo);
char *rotate(const char *text, int shift_key);

#endif
