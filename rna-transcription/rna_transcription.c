#include <stdlib.h>
#include <stddef.h>
#include <string.h>

#include "rna_transcription.h"

char *to_rna(const char *dna)
{
  size_t len = strlen(dna);
  char *rna = malloc((len + 1) * sizeof(*rna));

  if (!rna)
    return NULL;
  
  for (unsigned int i = 0; dna[i]; i++)
  {
    switch (dna[i]) {
      case 'G':
        rna[i] = 'C';
        break;

      case 'C':
        rna[i] = 'G';
        break;

      case 'T':
        rna[i] = 'A';
        break;

      case 'A':
        rna[i] = 'U';
        break;

      default:
        rna[i] = dna[i];
    }
  }

  rna[len] = '\0';
  return rna;
}
