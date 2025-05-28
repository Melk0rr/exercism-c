#include "protein_translation.h"
#include <stdio.h>
#include <string.h>

const amino_acid_t amino_table[] = {
    [136] = Methionine, [85] = Phenylalanine, [152] = Phenylalanine, [150] = Leucine,    [118] = Leucine,
    [141] = Serine,     [123] = Serine,       [121] = Serine,        [97] = Serine,     [110] = Tyrosine,
    [148] = Tyrosine,   [151] = Cysteine,      [133] = Cysteine,      [99] = Tryptophan,
};

unsigned int hash_codon(const char *codon)
{
  unsigned int hash = 0;
  int c;
  while ((c = *codon++))
    hash = ((hash << 5) + hash) + c;

  return hash % codon[1] + codon[0];
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

      if (codon_hash == 86 || codon_hash == 145 || codon_hash == 149)
        return res;

      res.amino_acids[res.count++] = amino_table[codon_hash];
    }
    res.valid = true;
  }

  return res;
}
