#ifndef SUM_OF_MULTIPLES_H
#define SUM_OF_MULTIPLES_H

#include <stddef.h>

typedef struct mult_t {
  unsigned int *array; 
  unsigned int size;
} mult_t;

mult_t multiple(unsigned int factor, unsigned int limit);
mult_t merge_mult(mult_t *mults);
unsigned int sum(const unsigned int *factors, const size_t number_of_factors,
                 const unsigned int limit);

#endif
