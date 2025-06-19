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

typedef unsigned char (*callback_t)(unsigned char, unsigned char *);
typedef int (*ctg_cmd_t)(dice_t);

// Core functions
unsigned char *count_digits(dice_t dice);
unsigned char full_straight(dice_t dice, callback_t cb, unsigned char default_value, char condition_value);

// Callbacks
unsigned char full_house_cb(unsigned char index, unsigned char *counts);
unsigned char four_of_a_kind_cb(unsigned char index, unsigned char *counts);
unsigned char little_straight_cb(unsigned char index, unsigned char *counts);
unsigned char big_straight_cb(unsigned char index, unsigned char *counts);

// Category commands
int ones(dice_t dice);
int twos(dice_t dice);
int threes(dice_t dice);
int fours(dice_t dice);
int fives(dice_t dice);
int sixes(dice_t dice);
int choice(dice_t dice);
int full_house(dice_t dice);
int four_of_a_kind(dice_t dice);
int little_straight(dice_t dice);
int big_straight(dice_t dice);
int yacht(dice_t dice);
int score(dice_t dice, category_t category);

#endif
