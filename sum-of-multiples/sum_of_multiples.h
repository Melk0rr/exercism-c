#ifndef SUM_OF_MULTIPLES_H
#define SUM_OF_MULTIPLES_H

#include <stdlib.h>

typedef struct mult_t {
  unsigned int *array; 
  unsigned int size;
} mult_t;

void *xmalloc(size_t size);
mult_t *new_mult_t(unsigned int mult_size);
mult_t *multiple(unsigned int factor, unsigned int limit);
mult_t *merge_mult(mult_t *mults[], unsigned int merge_size, const size_t number_of_factors);
int compare_mult(const void *m1, const void *m2);
mult_t *remove_duplicates(mult_t *merged);
unsigned int sum(const unsigned int *factors, const size_t number_of_factors,
                 const unsigned int limit);

#endif
