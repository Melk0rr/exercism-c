#include "spiral_matrix.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

static void * xcalloc(size_t const nmemb, size_t const size)
{
  void *p = calloc(nmemb, size);

  if (!p)
  {
    fprintf(stderr, "Memory allocation failed");
    exit(EXIT_FAILURE);
  }

  return p;
}

static spiral_matrix_t * init_matrix(size_t const matrix_size)
{
  spiral_matrix_t * const new_spiral = xcalloc(1, sizeof(*new_spiral));
  new_spiral->size = matrix_size;

  if (matrix_size == 0)
    return new_spiral;

  new_spiral->matrix = xcalloc(matrix_size, sizeof(*new_spiral->matrix));
  for (size_t i = 0; i < matrix_size; i++)
    new_spiral->matrix[i] =
        xcalloc(matrix_size, sizeof(*new_spiral->matrix[i]));

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
