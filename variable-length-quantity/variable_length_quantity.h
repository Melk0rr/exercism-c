#ifndef VARIABLE_LENGTH_QUANTITY_H
#define VARIABLE_LENGTH_QUANTITY_H

#include <stddef.h>
#include <stdint.h>

/// Encode an array of integers into Variable Length Quantity.
///
/// The function returns the size of the output buffer used.
int encode(uint32_t const * const integers, size_t const integers_len,
           uint8_t * const output);

/// Decode a Variable Length Quantity byte array into an array of integers.
///
/// The function returns the size of the output buffer used or -1 if an error
/// occurred.
int decode(uint8_t const * const bytes, size_t const buffer_len,
           uint32_t * const output);

#endif
