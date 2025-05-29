#include "protein_translation.h"
#include <stdio.h>
#include <string.h>

const amino_acid_t amino_table[86][86][86] = {
  ['A'] = { ['U'] = { ['G'] = Methionine } },
  ['U'] = { 
    ['A'] = {
      ['A'] = -1,
      ['C'] = Tyrosine,
      ['G'] = -1,
      ['U'] = Tyrosine
    },
    ['C'] = {},
    ['G'] = {}, 
    ['U'] = {}
  }
};

unsigned int hash_codon(const char *codon)
{
  return ((codon[0] << 4) | (codon[1] << 8) | (codon[2] << 16)) / 10000;
}

protein_t protein(const char *const rna)
{
  protein_t res = {.valid = false, .count = 0};

  if (strlen(rna) % 3 == 0)
  {
    for (unsigned int i = 0; i < strlen(rna) / 3; i++)
    {
      const char *codon = rna + i * 3;
      unsigned int codon_hash = hash_codon(codon);
      printf("%d", codon_hash);
      //
      // if (codon_hash == 79 || codon_hash == 90 || codon_hash == 152)
      //   return res;
      //
      // res.amino_acids[res.count++] = amino_table[codon_hash];
    }
    res.valid = true;
  }

  return res;
}
