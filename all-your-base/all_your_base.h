#ifndef ALL_YOUR_BASE_H
#define ALL_YOUR_BASE_H

#include <stddef.h>
#include <stdint.h>

#define DIGITS_ARRAY_SIZE 64

size_t rebase(int8_t input_digits[], int16_t const input_base,
              int16_t const output_base, size_t const input_length);

#endif
