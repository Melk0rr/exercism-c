#include "yacht.h"
#include <stdlib.h>
typedef bool (*callback_t)(unsigned char, unsigned char *);
typedef int (*ctg_cmd_t)(dice_t);

// Core functions
unsigned char *count_digits(dice_t dice)
{
  unsigned char *counts = malloc(7 * sizeof(int));
  for (unsigned char i = 0; i < 5; i++)
    counts[dice.faces[i]]++;

  return counts;
}

unsigned char full_straight(dice_t dice, callback_t cb, unsigned char default_value, char condition_value)
{
  unsigned char *counts = count_digits(dice);
  for (unsigned char i = 1; i < 7; i++)
    if (cb(i, counts))
      return (condition_value == -1) ? i : condition_value;

  return default_value;
}

// Callbacks
unsigned char full_house_cb(unsigned char index, unsigned char *counts) { return counts[index] == 1 || counts[index] > 3; }
unsigned char four_of_a_kind_cb(unsigned char index, unsigned char *counts) { return counts[index] >= 4; }
unsigned char little_straight_cb(unsigned char index, unsigned char *counts) { return counts[index] != 1 && index != 6; }
unsigned char big_straight_cb(unsigned char index, unsigned char *counts) { return counts[index] != 1 && index != 1; }

// Category commands
int ones(dice_t dice) { return count_digits(dice)[1]; }
int twos(dice_t dice) { return count_digits(dice)[2] * 2; }
int threes(dice_t dice) { return count_digits(dice)[3] * 3; }
int fours(dice_t dice) { return count_digits(dice)[4] * 4; }
int fives(dice_t dice) { return count_digits(dice)[5] * 5; }
int sixes(dice_t dice) { return count_digits(dice)[6] * 6; }
int choice(dice_t dice) { return (dice.faces[0] + dice.faces[1] + dice.faces[2] + dice.faces[3] + dice.faces[4]); }
int full_house(dice_t dice) { return choice(dice) * full_straight(dice, full_house_cb, 1, 0); }
int four_of_a_kind(dice_t dice) { return 4 * full_straight(dice, four_of_a_kind_cb, 0, -1); }
int little_straight(dice_t dice) { return 30 * full_straight(dice, little_straight_cb, 1, 0); }
int big_straight(dice_t dice) { return 30 * full_straight(dice, big_straight_cb, 1, 0); }
int yacht(dice_t dice) { return (dice.faces[0] == dice.faces[1] && dice.faces[0] == dice.faces[2] && dice.faces[0] == dice.faces[3] && dice.faces[0] == dice.faces[4]) ? 50 : 0; }

static const ctg_cmd_t command_lookup[] = {
  [ONES] = ones                      , [TWOS] = twos                , [THREES] = threes        , [FOURS] = fours,
  [FIVES] = fives                    , [SIXES] = sixes              , [FULL_HOUSE] = full_house, [FOUR_OF_A_KIND] = four_of_a_kind,
  [LITTLE_STRAIGHT] = little_straight, [BIG_STRAIGHT] = big_straight, [CHOICE] = choice        , [YACHT] = yacht};

int score(dice_t dice, category_t category) { return command_lookup[category](dice); }
