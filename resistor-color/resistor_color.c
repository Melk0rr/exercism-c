#include "resistor_color.h"

unsigned int color_code(resistor_band_t col) { return col; }

resistor_band_t *colors()
{
  static resistor_band_t cols[] = {BLACK, BROWN, RED, ORANGE, YELLOW, GREEN, BLUE, VIOLET, GREY, WHITE};
  return cols;
}
