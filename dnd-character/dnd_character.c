#include <math.h>
#include <stdlib.h>
#include <time.h>

#include "dnd_character.h"

static int roll_dice(void) { return rand() % 6 + 1; }

int ability(void)
{
  srand(time(0));

  unsigned short int rolls[3] = {roll_dice(), roll_dice(), roll_dice()};
  unsigned short int roll4 = roll_dice();
  unsigned short int min_index = 0;

  if (roll4 > rolls[0] || roll4 > rolls[1] || roll4 > rolls[2])
  {
    for (unsigned short int i = 1; i < 3; ++i)
      if (rolls[i] < rolls[min_index])
        min_index = i;

    rolls[min_index] = roll4;
  }

  return rolls[0] + rolls[1] + rolls[2];
}

int modifier(int score) { return floor((float)(score - 10) / 2); }

dnd_character_t make_dnd_character(void)
{
  dnd_character_t rnd_char = {ability(), ability(), ability(), ability(), ability(), ability(), 0};
  rnd_char.hitpoints = 10 + modifier(rnd_char.constitution);

  return rnd_char;
}
