#include "yacht.h"
#include <stdbool.h>

typedef bool (*callback_t)(unsigned char, unsigned char *);
typedef int (*ctg_cmd_t)(dice_t);
typedef struct {
  unsigned char counts[7];
} face_counts_t;

// Core functions
static face_counts_t count_digits(dice_t dice)
{
  face_counts_t fc = {0};
  for (unsigned char i = 0; i < 5; i++)
    fc.counts[dice.faces[i]]++;

  return fc;
}

static int find_face_index(dice_t dice, callback_t cb)
{
  face_counts_t fc = count_digits(dice);
  int res = 0;
  for (unsigned char i = 1; i < 7; i++)
    if (cb(i, fc.counts))
    {
      res = i;
      break;
    }

  return res;
}

// Callbacks
static bool full_house_cb(unsigned char index, unsigned char *counts) { return counts[index] == 1 || counts[index] > 3; }
static bool four_of_a_kind_cb(unsigned char index, unsigned char *counts) { return counts[index] >= 4; }
static bool little_straight_cb(unsigned char index, unsigned char *counts) { return counts[index] != 1 && index != 6; }
static bool big_straight_cb(unsigned char index, unsigned char *counts) { return counts[index] != 1 && index != 1; }

// Category commands
static int ones(dice_t dice) { return count_digits(dice).counts[1]; }
static int twos(dice_t dice) { return count_digits(dice).counts[2] * 2; }
static int threes(dice_t dice) { return count_digits(dice).counts[3] * 3; }
static int fours(dice_t dice) { return count_digits(dice).counts[4] * 4; }
static int fives(dice_t dice) { return count_digits(dice).counts[5] * 5; }
static int sixes(dice_t dice) { return count_digits(dice).counts[6] * 6; }
static int choice(dice_t dice) { return (dice.faces[0] + dice.faces[1] + dice.faces[2] + dice.faces[3] + dice.faces[4]); }
static int full_house(dice_t dice) { return choice(dice) * (find_face_index(dice, full_house_cb) == 0); }
static int four_of_a_kind(dice_t dice) { return 4 * find_face_index(dice, four_of_a_kind_cb); }
static int little_straight(dice_t dice) { return 30 * (find_face_index(dice, little_straight_cb) == 0); }
static int big_straight(dice_t dice) { return 30 * (find_face_index(dice, big_straight_cb) == 0); }
static int yacht(dice_t dice) { return 50 * (dice.faces[0] == dice.faces[1] && dice.faces[0] == dice.faces[2] && dice.faces[0] == dice.faces[3] && dice.faces[0] == dice.faces[4]); }

static const ctg_cmd_t command_lookup[] = {
  [ONES] = ones                      , [TWOS] = twos                , [THREES] = threes        , [FOURS] = fours,
  [FIVES] = fives                    , [SIXES] = sixes              , [FULL_HOUSE] = full_house, [FOUR_OF_A_KIND] = four_of_a_kind,
  [LITTLE_STRAIGHT] = little_straight, [BIG_STRAIGHT] = big_straight, [CHOICE] = choice        , [YACHT] = yacht
};

int score(dice_t dice, category_t category) { return command_lookup[category](dice); }
