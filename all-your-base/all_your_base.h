#ifndef ALL_YOUR_BASE_H
#define ALL_YOUR_BASE_H

#include <stddef.h>
#include <stdint.h>

#define DIGITS_ARRAY_SIZE 64

size_t rebase(int8_t input_digits[], int16_t input_base, int16_t output_base, size_t input_length);

#endif
