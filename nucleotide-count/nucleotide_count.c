#include "nucleotide_count.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// TODO: check malloc size (30) + strcpy
char *count(const char *dna_strand)
{
  int tracker[] = {
      ['A'] = 0,
      ['C'] = 0,
      ['G'] = 0,
      ['T'] = 0,
  };

  unsigned char invalid = 0;
  for (unsigned int i = 0; i < strlen(dna_strand); i++)
  {
    if (dna_strand[i] != 'A' && dna_strand[i] != 'C' && dna_strand[i] != 'G' && dna_strand[i] != 'T')
    {
      invalid = 1;
      break;
    }
    tracker[(int)dna_strand[i]]++;
  }

  if (invalid == 1)
    return calloc(1, sizeof(char));

  char *count_str = malloc(strlen(dna_strand) * sizeof(char));
  sprintf(count_str, "A:%d C:%d G:%d T:%d", tracker['A'], tracker['C'], tracker['G'], tracker['T']);

  return count_str;
}
