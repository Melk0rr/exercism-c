#include "protein_translation.h"
#include <string.h>

const amino_acid_t amino_table[86][86][86] = {
    ['A'] = {['U'] = {['G'] = Methionine}},
    ['U'] = {['A'] = {['A'] = -1, ['C'] = Tyrosine, ['G'] = -1, ['U'] = Tyrosine},
             ['C'] = {['A'] = Serine, ['C'] = Serine, ['G'] = Serine, ['U'] = Serine},
             ['G'] = {['A'] = -1, ['C'] = Cysteine, ['G'] = Tryptophan, ['U'] = Cysteine},
             ['U'] = {['A'] = Leucine, ['C'] = Phenylalanine, ['G'] = Leucine, ['U'] = Phenylalanine}}};

protein_t protein(const char *const rna)
{
  protein_t res = {.valid = false, .count = 0};

  if (strlen(rna) % 3 == 0)
  {
    for (unsigned int i = 0; i < strlen(rna) / 3; i++)
    {
      const char *codon = rna + i * 3;
      amino_acid_t amino = amino_table[(int)codon[0]][(int)codon[1]][(int)codon[2]];

      if ((int)amino == -1)
      {
        res.valid = true;
        return res; 
      }

      res.amino_acids[res.count++] = amino; 
    }
    res.valid = true;
  }

  return res;
}
