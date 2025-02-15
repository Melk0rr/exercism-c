#include "darts.h"
#include <math.h>

uint8_t score( coordinate_t pos) 
{
  float dist = sqrt(pow(pos.x, 2) + pow(pos.y, 2));
  return dist > 10.0F ? 0 : dist > 5.0F ? 1 : dist > 1.0F ? 5 : 10;
}
