#include "kindergarten_garden.h"
#include <string.h>

static const plant_t plant_encoding[] = {
    ['C'] = CLOVER,
    ['G'] = GRASS,
    ['R'] = RADISHES,
    ['V'] = VIOLETS,
};

plants_t plants(const char *diagram, const char *student)
{
  size_t garden_row_size = (strlen(diagram) - 1) / 2;
  char garden_row1[garden_row_size], garden_row2[garden_row_size];
  memcpy(garden_row1, &diagram[0], garden_row_size);
  memcpy(garden_row2, &diagram[garden_row_size + 1], garden_row_size);

  unsigned char student_i = (student[0] - 65) * 2;
  return (plants_t){
      .plants = {plant_encoding[(int)garden_row1[student_i]], plant_encoding[(int)garden_row1[student_i + 1]],
                 plant_encoding[(int)garden_row2[student_i]], plant_encoding[(int)garden_row2[student_i + 1]]}};
}
