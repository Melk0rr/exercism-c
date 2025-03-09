#include <math.h>
#include "resistor_color_trio.h"

resistor_value_t color_code(resistor_band_t *col)
{
  resistor_value_t resistor;
  resistor.value = (col[0] * 10 + col[1]) * pow(10, col[2]);

  if (resistor.value < 1000)
    resistor.unit = OHMS;
  else if (resistor.value < 1000000)
    resistor.unit = KILOOHMS;
  else if (resistor.value < 1000000000)
    resistor.unit = MEGAOHMS;
  else
    resistor.unit = GIGAOHMS;

  resistor.value /= pow(1000, resistor.unit);

  return resistor;
}
