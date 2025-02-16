#include <stdio.h>
#include <string.h>

#include "rna_transcription.h"

static const char dna_to_rna[] = {
  ['G'] = 'C',
  ['C'] = 'G',
  ['T'] = 'A',
  ['A'] = 'U',
};

char *to_rna(const char *dna)
{
  char *rna = "";
  for (unsigned int i = 0; i < strlen(dna); i++)
    rna += dna_to_rna[dna[i]];

  return rna;
}
