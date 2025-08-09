#include "spiral_matrix.h"
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

static void * xmalloc(size_t const size, char const * const err)
{
  void * p = malloc(size);

  if (!p)
  {
    fprintf(stderr, "%s\n", err);
    exit(EXIT_FAILURE);
  }

  return p;
}

static spiral_matrix_t * init_matrix(size_t const matrix_size)
{
  spiral_matrix_t * const new_spiral = xmalloc(
      sizeof(*new_spiral), "Memory allocation failed for new spiral matrix");

  new_spiral->size = matrix_size;

  if (matrix_size != 0)
  {
    new_spiral->matrix = xmalloc(matrix_size * sizeof(*new_spiral->matrix),
                                 "Memory allocation failed for spiral matrix");

    for (size_t i = 0; i < matrix_size; i++)
      new_spiral->matrix[i] =
          calloc(matrix_size, sizeof(*new_spiral->matrix[i]));
  }

  return new_spiral;
}

spiral_matrix_t * spiral_matrix_create(int const matrix_size)
{
  spiral_matrix_t * const new_spiral = init_matrix(matrix_size);

  int8_t dx = 1, dy = 0;
  int x = 0, y = 0;
  for (size_t i = 0; i < matrix_size * matrix_size; i++)
  {
    new_spiral->matrix[y][x] = i + 1;

    int nx = x + dx, ny = y - dy;
    if ((nx >= matrix_size) || (ny >= matrix_size) || (nx < 0) || (ny < 0) ||
        (new_spiral->matrix[ny][nx]))
    {
      int8_t temp_dx = dx;
      dx = dy;
      dy = -temp_dx;
    }

    x += dx;
    y -= dy;
  }

  return new_spiral;
}

void spiral_matrix_destroy(spiral_matrix_t * const spiral)
{
  for (size_t i = 0; i < spiral->size; i++)
    free(spiral->matrix[i]);

  free(spiral->matrix);
  free(spiral);
}
