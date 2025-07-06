#include "variable_length_quantity.h"

int encode(const uint32_t *integers, size_t integers_len, uint8_t *output)
{
  // write to `output`, return final output's length
  // `output` buffer should be enough to hold the full result
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
      uint8_t byte = bytes[j];
      if (j != 0)
        byte |= (1u << 7);

      output[size++] = byte;
    }
  }

  return size;
}

int decode(const uint8_t *bytes, size_t buffer_len, uint32_t *output)
{
  // write to `output`, return final output's length
  // return -1 if error
  // `output` buffer should be enough to hold the full result
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
