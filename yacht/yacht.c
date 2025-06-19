#include "yacht.h"
#include <stdlib.h>
#include <stdbool.h>

typedef bool (*callback_t)(unsigned char, unsigned char *);
typedef int (*ctg_cmd_t)(dice_t);

// Core functions
static unsigned char *count_digits(dice_t dice)
{
  unsigned char *counts = calloc(6, sizeof(int));
  if (counts == NULL)
    abort();

  for (unsigned char i = 0; i < 5; i++)
    counts[dice.faces[i] - 1]++;

  return counts;
}

static int get_score_mult(dice_t dice, callback_t cb, unsigned char default_score_mult)
{
  unsigned char *counts = count_digits(dice);
  for (unsigned char i = 0; i < 6; i++)
    if (cb(i, counts))
      return (default_score_mult == 0) ? i + 1 : 0;

  free(counts);
  return default_score_mult;
}

// Callbacks
static bool full_house_cb(unsigned char index, unsigned char *counts) { return counts[index] == 1 || counts[index] > 3; }
static bool four_of_a_kind_cb(unsigned char index, unsigned char *counts) { return counts[index] >= 4; }
static bool little_straight_cb(unsigned char index, unsigned char *counts) { return counts[index] != 1 && index != 5; }
static bool big_straight_cb(unsigned char index, unsigned char *counts) { return counts[index] != 1 && index != 0; }

// Category commands
static int ones(dice_t dice) { return count_digits(dice)[0]; }
static int twos(dice_t dice) { return count_digits(dice)[1] * 2; }
static int threes(dice_t dice) { return count_digits(dice)[2] * 3; }
static int fours(dice_t dice) { return count_digits(dice)[3] * 4; }
static int fives(dice_t dice) { return count_digits(dice)[4] * 5; }
static int sixes(dice_t dice) { return count_digits(dice)[5] * 6; }
static int choice(dice_t dice) { return (dice.faces[0] + dice.faces[1] + dice.faces[2] + dice.faces[3] + dice.faces[4]); }
static int full_house(dice_t dice) { return choice(dice) * get_score_mult(dice, full_house_cb, 1); }
static int four_of_a_kind(dice_t dice) { return 4 * get_score_mult(dice, four_of_a_kind_cb, 0); }
static int little_straight(dice_t dice) { return 30 * get_score_mult(dice, little_straight_cb, 1); }
static int big_straight(dice_t dice) { return 30 * get_score_mult(dice, big_straight_cb, 1); }
static int yacht(dice_t dice) { return (dice.faces[0] == dice.faces[1] && dice.faces[0] == dice.faces[2] && dice.faces[0] == dice.faces[3] && dice.faces[0] == dice.faces[4]) ? 50 : 0; }

static const ctg_cmd_t command_lookup[] = {
  [ONES] = ones                      , [TWOS] = twos                , [THREES] = threes        , [FOURS] = fours,
  [FIVES] = fives                    , [SIXES] = sixes              , [FULL_HOUSE] = full_house, [FOUR_OF_A_KIND] = four_of_a_kind,
  [LITTLE_STRAIGHT] = little_straight, [BIG_STRAIGHT] = big_straight, [CHOICE] = choice        , [YACHT] = yacht
};

int score(dice_t dice, category_t category) { return command_lookup[category](dice); }
