#include "resistor_color_duo.h"

unsigned int color_code(resistor_band_t *col)
{
  return col[0] * 10 + col[1];
}
