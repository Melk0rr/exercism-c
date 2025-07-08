#ifndef PROTEIN_TRANSLATION_H
#define PROTEIN_TRANSLATION_H

#include <stdbool.h>
#include <stddef.h>

#define MAX_AMINO_ACIDS 10

typedef enum
{
  Methionine = 1,
  Phenylalanine = 2,
  Leucine = 3,
  Serine = 4,
  Tyrosine = 5,
  Cysteine = 6,
  Tryptophan = 7,
} amino_acid_t;

typedef struct
{
  bool valid;
  size_t count;
  amino_acid_t amino_acids[MAX_AMINO_ACIDS];
} protein_t;

protein_t protein(char const * const rna);

#endif
