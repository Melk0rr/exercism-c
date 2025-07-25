#include "variable_length_quantity.h"

int encode(uint32_t const * const integers, size_t const integers_len,
           uint8_t * const output)
{
  size_t size = 0;
  for (size_t i = 0; i < integers_len; i++)
  {
    uint8_t bytes[5];
    uint8_t tmp_len = 0;
    uint32_t n = integers[i];

    do
    {
      bytes[tmp_len++] = n & 0x7F;
      n >>= 7;
    } while (n);

    for (int j = tmp_len - 1; j >= 0; j--)
    {
      if (j != 0)
        bytes[j] |= (1u << 7);

      output[size++] = bytes[j];
    }
  }

  return size;
}

int decode(uint8_t const * const bytes, size_t const buffer_len,
           uint32_t * const output)
{
  if ((buffer_len > 0) && (bytes[buffer_len - 1] & 0x80))
    return -1;

  size_t size = 0;
  uint32_t integer = 0;
  for (size_t i = 0; i < buffer_len; i++)
  {
    integer = (integer << 7) | (bytes[i] & 0x7F);
    if ((bytes[i] & 0x80) == 0)
    {
      output[size++] = integer;
      integer = 0;
    }
  }

  return size;
}
