#ifndef SPIRAL_MATRIX_H
#define SPIRAL_MATRIX_H

#include <stddef.h>
typedef struct
{
  size_t size;
  int ** matrix;
} spiral_matrix_t;

spiral_matrix_t * spiral_matrix_create(int const matrix_size);
void spiral_matrix_destroy(spiral_matrix_t * const spiral);

#endif
