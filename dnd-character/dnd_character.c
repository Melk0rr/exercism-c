#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#include "dnd_character.h"

static int roll_dice(void) { return rand() % 6 + 1; }

int ability(void)
{
  srand(time(0));

  uint8_t min_index = 0;
  uint8_t const roll4 = roll_dice();
  uint8_t rolls[3] = {roll_dice(), roll_dice(), roll_dice()};

  if (roll4 > rolls[0] || roll4 > rolls[1] || roll4 > rolls[2])
  {
    for (unsigned short int i = 1; i < 3; ++i)
      if (rolls[i] < rolls[min_index])
        min_index = i;

    rolls[min_index] = roll4;
  }

  return rolls[0] + rolls[1] + rolls[2];
}

int modifier(int const score) { return floor((float)(score - 10) / 2); }

dnd_character_t make_dnd_character(void)
{
  dnd_character_t rnd_char = {ability(), ability(), ability(), ability(),
                              ability(), ability(), 0};
  rnd_char.hitpoints = 10 + modifier(rnd_char.constitution);

  return rnd_char;
}
