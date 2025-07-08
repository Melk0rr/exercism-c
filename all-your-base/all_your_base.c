#include "all_your_base.h"

size_t rebase(int8_t input_digits[], int16_t input_base, int16_t output_base, size_t input_length)
{
  if (input_base < 2 || output_base < 2 || input_length == 0)
    return 0;

  uint64_t value = 0;
  for (size_t i = 0; i < input_length; i++)
  {
    if (input_digits[i] >= input_base || input_digits[i] < 0)
      return 0;

    value = value * input_base + input_digits[i];
  }

  int8_t temp[DIGITS_ARRAY_SIZE];
  size_t output_len = 0;
  do
  {
    temp[output_len++] = value % output_base;
    value /= output_base;
  } while (value > 0);

  for (size_t i = 0; i < output_len; i++)
    input_digits[i] = temp[output_len - 1 - i];

  return output_len;
}
