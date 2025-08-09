#ifndef SPIRAL_MATRIX_H
#define SPIRAL_MATRIX_H

#include <stddef.h>
typedef struct
{
  int size;
  int ** matrix;
} spiral_matrix_t;

spiral_matrix_t * spiral_matrix_create(size_t const matrix_size);
void spiral_matrix_destroy(spiral_matrix_t const * const matrix);

#endif
