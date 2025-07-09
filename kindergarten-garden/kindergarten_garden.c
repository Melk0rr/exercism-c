#include "kindergarten_garden.h"
#include <stdint.h>
#include <string.h>

plants_t plants(char const * const diagram, char const * const student)
{
  size_t const garden_row_size = (strlen(diagram) - 1) / 2;
  char garden_row1[garden_row_size], garden_row2[garden_row_size];
  memcpy(garden_row1, &diagram[0], garden_row_size);
  memcpy(garden_row2, &diagram[garden_row_size + 1], garden_row_size);

  uint8_t const student_i = (student[0] - 65) * 2;
  return (plants_t){.plants = {garden_row1[student_i], garden_row1[student_i + 1], garden_row2[student_i],
                               garden_row2[student_i + 1]}};
}
