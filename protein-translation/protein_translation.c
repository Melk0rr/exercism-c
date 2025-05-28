#include "protein_translation.h"
#include <string.h>

protein_t protein(const char *const rna)
{
  protein_t res = { .valid = false, .count = 0 };

  if (strlen(rna) % 3 != 0)
    return res;

  return res;
}
