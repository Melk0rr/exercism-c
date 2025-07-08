#ifndef KINDERGARTEN_GARDEN_H
#define KINDERGARTEN_GARDEN_H

typedef enum
{
  CLOVER = 'C',
  GRASS = 'G',
  RADISHES = 'R',
  VIOLETS = 'V'
} plant_t;

typedef struct
{
  plant_t plants[4];
} plants_t;

plants_t plants(char const * const diagram, char const * const student);

#endif
