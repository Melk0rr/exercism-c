#include "protein_translation.h"
#include <string.h>

#define UPPER_A 65

static const amino_acid_t amino_table[26][26][26] = {
    [0] = {[20] = {[6] = Methionine}},
    [20] = {[0] = {[0] = -1, [2] = Tyrosine, [6] = -1, [20] = Tyrosine},
            [2] = {[0] = Serine, [2] = Serine, [6] = Serine, [20] = Serine},
            [6] = {[0] = -1, [2] = Cysteine, [6] = Tryptophan, [20] = Cysteine},
            [20] = {[0] = Leucine, [2] = Phenylalanine, [6] = Leucine, [20] = Phenylalanine}}};

protein_t protein(const char *const rna)
{
  protein_t res = {.valid = true, .count = 0};
  for (unsigned int i = 0; i < strlen(rna); i += 3)
  {
    const char *codon = rna + i;
    amino_acid_t amino = amino_table[codon[0] - UPPER_A][codon[1] - UPPER_A][codon[2] - UPPER_A];

    if (!amino)
      res.valid = false;

    if ((int)amino < 1)
      break;

    res.amino_acids[res.count++] = amino;
  }

  return res;
}
