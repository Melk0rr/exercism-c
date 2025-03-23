#ifndef LUHN_H
#define LUHN_H

#include <stdbool.h>

bool is_valid_char(char cc);
int double_digit(int digit);
bool luhn(const char *num);

#endif
