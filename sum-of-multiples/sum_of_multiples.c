#include "sum_of_multiples.h"
#include <stdlib.h>

void *xmalloc(size_t size)
{
  void *p = malloc(size);

  if (p == NULL)
    abort();

  return p;
}

mult_t *new_mult_t(unsigned int mult_size)
{
  mult_t *new_mult = xmalloc(sizeof(*new_mult));
  new_mult->array = xmalloc(mult_size * sizeof(unsigned int));
  new_mult->size = 0;

  return new_mult;
}

mult_t *multiple(unsigned int factor, unsigned int limit)
{
  unsigned int mult_count = factor == 0 ? 1 : (limit - 1) / factor;
  mult_t *factor_mult = new_mult_t(mult_count);

  unsigned int mult = 0;
  for (unsigned int i = 1; i <= mult_count; i++)
  {
    mult = factor * i;
    factor_mult->array[i - 1] = mult;
    factor_mult->size++;
  }

  return factor_mult;
}

mult_t *merge_mult(mult_t *mults[], unsigned int merged_size, const size_t number_of_factors)
{
  mult_t *merged = new_mult_t(merged_size);

  for (unsigned int i = 0; i < number_of_factors; i++)
    for (unsigned int j = 0; j < mults[i]->size; j++)
      merged->array[merged->size++] = mults[i]->array[j];

  return merged;
}

int compare_mult(const void *m1, const void *m2) { return (*(int *)m1) - (*(int *)m2); }

mult_t *remove_duplicates(mult_t *merged)
{
  qsort(merged->array, merged->size, sizeof(unsigned int), compare_mult);

  unsigned int cleaned_i = 0;
  for (unsigned int i = 0; i < merged->size; i++)
    if (i == 0 || merged->array[i] != merged->array[i - 1])
      merged->array[cleaned_i++] = merged->array[i];

  mult_t *cleaned = new_mult_t(cleaned_i);
  for (unsigned int i = 0; i < cleaned_i; i++)
    cleaned->array[i] = merged->array[i];

  free(merged);
  cleaned->size = cleaned_i;
  return cleaned;
}

unsigned int sum(const unsigned int *factors, const size_t number_of_factors, const unsigned int limit)
{

  mult_t *multiple_arrays[number_of_factors];
  unsigned int total_size = 0;

  // NOTE: Step 1: Genereate the arrays of multiples
  for (unsigned int i = 0; i < number_of_factors; i++)
  {
    multiple_arrays[i] = multiple(factors[i], limit);
    total_size += multiple_arrays[i]->size;
  }

  // NOTE: Step 2: Merge the arrays
  mult_t *merged = merge_mult(multiple_arrays, total_size, number_of_factors);

  // NOTE: Step 3: Remove duplicated multiples
  mult_t *cleaned = remove_duplicates(merged);

  // NOTE: Step 4: Sum the multiples
  unsigned int sum = 0;
  for (unsigned int i = 0; i < cleaned->size; i++)
    sum += cleaned->array[i];

  free(cleaned);
  for (unsigned int i = 0; i < number_of_factors; i++)
    free(multiple_arrays[i]);

  return sum;
}
