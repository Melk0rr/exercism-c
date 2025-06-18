#ifndef YACHT_H
#define YACHT_H

typedef enum
{
  ONES,
  TWOS,
  THREES,
  FOURS,
  FIVES,
  SIXES,
  FULL_HOUSE,
  FOUR_OF_A_KIND,
  LITTLE_STRAIGHT,
  BIG_STRAIGHT,
  CHOICE,
  YACHT
} category_t;

typedef struct
{
  int faces[5];
} dice_t;

struct ctg_cmd
{
  int (*func)(dice_t dice);
};

int *count_digit(dice_t dice);
int ones(dice_t dice);
int twos(dice_t dice);
int threes(dice_t dice);
int fours(dice_t dice);
int fives(dice_t dice);
int sixes(dice_t dice);
int full_house(dice_t dice);
int yacht(dice_t dice);
int score(dice_t dice, category_t category);

#endif
