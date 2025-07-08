#include "nucleotide_count.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *count(char const * const dna_strand)
{
  int tracker[] = {['A'] = 0, ['C'] = 0, ['G'] = 0, ['T'] = 0};
  char * const count_str = malloc(30);

  for (size_t i = 0; i < strlen(dna_strand); i++)
  {
    if (dna_strand[i] != 'A' && dna_strand[i] != 'C' && dna_strand[i] != 'G' && dna_strand[i] != 'T')
    {
      strcpy(count_str, "");
      return count_str;
    }

    tracker[(int)dna_strand[i]]++;
  }

  sprintf(count_str, "A:%d C:%d G:%d T:%d", tracker['A'], tracker['C'], tracker['G'], tracker['T']);
  return count_str;
}
