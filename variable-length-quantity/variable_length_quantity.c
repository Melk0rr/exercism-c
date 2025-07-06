#include "variable_length_quantity.h"
#include <stdio.h>

int encode(const uint32_t *integers, size_t integers_len, uint8_t *output)
{
  // write to `output`, return final output's length
  // `output` buffer should be enough to hold the full result

  if (integers_len == 1 && integers[0] == 0)
  {
    output[0] = (uint8_t)0;
    return 1;
  }

  int size = 0;
  for (uint8_t i = 0; i < integers_len; i++) {
    uint8_t digits[32];

    uint8_t digit_i = 0;
    uint32_t n = integers[i];

    if (n == 0)
      digits[digit_i++] = 0;

    else
      while(n > 0)
      {
        digits[digit_i++] = n % 128;
        n /= 128;
      }

    printf("digit number: %hhu\n", digit_i);

    for (int j = digit_i - 1; j >= 0; j--) {
      printf("digit: %d; ", digits[j]);
      if (j >= 1)
        digits[j] |= (1u << 7);

      output[size++] = digits[j];
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
