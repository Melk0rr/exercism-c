#include "yacht.h"
#include <stdlib.h>

int* count_digit(dice_t dice)
{
  int *counts = malloc(7 * sizeof(int));
  for (unsigned int i = 0; i < 5; i++)
    counts[dice.faces[i]]++;

  return counts;
}

int ones(dice_t dice) { return count_digit(dice)[1]; }
int twos(dice_t dice) { return count_digit(dice)[2] * 2; }
int threes(dice_t dice) { return count_digit(dice)[3] * 3; }
int fours(dice_t dice) { return count_digit(dice)[4] * 4; }
int fives(dice_t dice) { return count_digit(dice)[5] * 5; }
int sixes(dice_t dice) { return count_digit(dice)[6] * 6; }
int full_house(dice_t dice) {
  int *counts = count_digit(dice);
  unsigned char full_house = 1;

  for (int i = 1; i < 7; i++)
    if (counts[i] == 1 || counts[i] > 3)
    {
      full_house = 0;
      break;
    }

  return (dice.faces[0] + dice.faces[1] + dice.faces[2] + dice.faces[3] + dice.faces[4]) * full_house;
}
int yacht(dice_t dice)
{
  return (dice.faces[0] == dice.faces[1] && dice.faces[0] == dice.faces[2] && dice.faces[0] == dice.faces[3] &&
          dice.faces[0] == dice.faces[4])
             ? 50
             : 0;
}

static const struct ctg_cmd command_lookup[] = {
    [ONES] = {ones},   [TWOS] = {twos},   [THREES] = {threes},         [FOURS] = {fours},
    [FIVES] = {fives}, [SIXES] = {sixes}, [FULL_HOUSE] = {full_house}, [YACHT] = {yacht}};

int score(dice_t dice, category_t category)
{
  const struct ctg_cmd *category_command = &command_lookup[category];
  return category_command->func(dice);
}
