#include "space_age.h"
#include <stdint.h>

static double periods[] = {
  0.2408467,
  0.61519726,
  1.0,
  1.8808158,
  11.862615,
  29.447498,
  84.016846,
  164.79132 
};

float age(planet_t planet, int64_t seconds)
{
  return ((int)planet < 0) ? -1 : (365.25 / (365.25 * periods[(int)planet])) * ((float)seconds / 60 / 60 / 24 / 365.25);
}
