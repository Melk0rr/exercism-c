#include "raindrops.h"
#include <stdio.h>
#include <string.h>

void convert(char result[], int const drops)
{
  if (drops % 3 == 0)
    strcat(result, "Pling");

  if (drops % 5 == 0)
    strcat(result, "Plang");

  if (drops % 7 == 0)
    strcat(result, "Plong");

  if (strlen(result) == 0)
    sprintf(result, "%d", drops);
}
