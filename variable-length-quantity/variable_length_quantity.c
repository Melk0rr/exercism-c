#include "variable_length_quantity.h"
#include <stdio.h>

int encode(const uint32_t *integers, size_t integers_len, uint8_t *output)
{
  // write to `output`, return final output's length
  // `output` buffer should be enough to hold the full result
  int size = 0;
  for (uint8_t i = 0; i < integers_len; i++) {
    uint8_t digits[32];

    if (integers_len == 1 && integers[0] == 0)
    {
      output[0] = (uint8_t)0;
      return 1;
    }

    uint8_t digit_i = 0;
    uint32_t n = integers[i];
    while(n > 0)
    {
      digits[digit_i++] = integers[i] % 128;
      n /= 128;
    }

    if (digit_i > 1)
      digits[digit_i - 1] |= (1u << 7);

    printf("digit number: %hhu\n", digit_i);

    for (int j = digit_i - 1; j >= 0; j--) {
      printf("digit: %d; ", digits[j]);
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
  output[0] = (uint8_t)0;
  printf("(%d), %zu", bytes[0], buffer_len);
  return 1;
}
