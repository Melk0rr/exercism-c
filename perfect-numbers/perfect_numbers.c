#include "perfect_numbers.h"

kind classify_number(int num) {
  if (num < 1)
    return ERROR;

  int sum = 0;

  for (int i = 1; i <= num / 2; i++)
    if (num % i == 0)
      sum += i;

  return (sum == num) ? PERFECT_NUMBER : (sum > num) ? ABUNDANT_NUMBER : DEFICIENT_NUMBER;
}
