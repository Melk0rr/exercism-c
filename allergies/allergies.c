#include "allergies.h"
#include <stddef.h>

bool is_allergic_to(allergen_t const allergen, uint16_t const score)
{
  return score & allergen;
}

allergen_list_t get_allergens(uint16_t const score)
{
  allergen_list_t all_list;

  all_list.count = 0;
  for (size_t i = 0; i < 8; i++)
  {
    all_list.allergens[1 << i] = is_allergic_to(1 << i, score);
    if (all_list.allergens[1 << i])
      all_list.count++;
  }

  return all_list;
}
