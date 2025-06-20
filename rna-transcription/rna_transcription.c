#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "rna_transcription.h"

static int transcription_table[] = {
    ['G'] = 'C',
    ['C'] = 'G',
    ['T'] = 'A',
    ['A'] = 'U',
};

char *to_rna(const char *dna)
{
  size_t len = strlen(dna);
  char *rna = malloc((len + 1) * sizeof(*rna));

  if (!rna)
    return NULL;

  for (unsigned int i = 0; dna[i]; i++)
    rna[i] =
        (dna[i] == 'G' || dna[i] == 'C' || dna[i] == 'T' || dna[i] == 'A') ? transcription_table[(int)dna[i]] : dna[i];

  rna[len] = '\0';
  return rna;
}
