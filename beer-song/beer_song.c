#include "beer_song.h"
#include <stdio.h>

static char const * const FIRST_LINE_OPT[] = {
    "No more bottles of beer on the wall, no more bottles of beer.",
    "1 bottle of beer on the wall, 1 bottle of beer.",
    "%u bottles of beer on the wall, %u bottles of beer."};

static char const * const SECOND_LINE_OPT[] = {
    "Go to the store and buy some more, 99 bottles of beer on the wall.",
    "Take it down and pass it around, no more bottles of beer on the wall.",
    "Take one down and pass it around, 1 bottle of beer on the wall.",
    "Take one down and pass it around, %u bottles of beer on the wall."};

void recite(uint8_t const start_bottles, uint8_t const take_down, char * const * song)
{
  uint8_t const last_bottle = start_bottles - (take_down - 1);
  for (int bottle = start_bottles; bottle >= last_bottle; bottle--)
  {
    sprintf(*song++, FIRST_LINE_OPT[bottle > 1 ? 2 : bottle], bottle, bottle);
    sprintf(*song++, SECOND_LINE_OPT[bottle - 1 > 2 ? 3 : bottle], bottle - 1);
    song++;
  }
}
