#ifndef ALLERGIES_H
#define ALLERGIES_H

#include <stdbool.h>
#include <stdint.h>

typedef enum {
   ALLERGEN_EGGS = (1 << 0),
   ALLERGEN_PEANUTS = (1 << 1),
   ALLERGEN_SHELLFISH = (1 << 2),
   ALLERGEN_STRAWBERRIES = (1 << 3),
   ALLERGEN_TOMATOES = (1 << 4),
   ALLERGEN_CHOCOLATE = (1 << 5),
   ALLERGEN_POLLEN = (1 << 6),
   ALLERGEN_CATS = (1 << 7),
   ALLERGEN_COUNT = (1 << 8),
} allergen_t;

typedef struct {
   int count;
   bool allergens[ALLERGEN_COUNT];
} allergen_list_t;

bool is_allergic_to(allergen_t allergen, const uint16_t score);
allergen_list_t get_allergens(const uint16_t score);

#endif
