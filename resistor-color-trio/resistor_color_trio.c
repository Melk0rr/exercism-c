#include <stdio.h>
#include <math.h>
#include "resistor_color_trio.h"

resistor_value_t color_code(resistor_band_t *col)
{
  resistor_value_t resistor;

  resistor.value = (col[0] * 10 + col[1]) * pow(10, col[2]);

  printf("Value: %lu", resistor.value);

  if (resistor.value < 1000)
    resistor.unit = OHMS;

  else if (resistor.value < 1000000) {
    resistor.unit = KILOOHMS;
    resistor.value /= 1000;
  }
  else if (resistor.value < 1000000000) {
    resistor.unit = MEGAOHMS;
    resistor.value /= 1000000;
  }
  else {
    resistor.unit = GIGAOHMS;
    resistor.value /= 1000000000;
  }

  return resistor;
}
