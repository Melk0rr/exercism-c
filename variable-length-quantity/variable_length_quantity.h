#ifndef VARIABLE_LENGTH_QUANTITY_H
#define VARIABLE_LENGTH_QUANTITY_H

#include <stddef.h>
#include <stdint.h>

int encode(uint32_t const * const integers, size_t const integers_len,
           uint8_t * const output);
int decode(uint8_t const * const bytes, size_t const buffer_len,
           uint32_t * const output);

#endif
