#include "triangle.h"

bool is_triangle(triangle_t triangle)
{
  return !(triangle.a == 0 || triangle.b == 0 || triangle.c == 0) && (triangle.a + triangle.b >= triangle.c) &&
         (triangle.b + triangle.c >= triangle.a) && (triangle.a + triangle.c >= triangle.b);
}

bool is_equilateral(triangle_t triangle)
{
  return is_triangle(triangle) && (triangle.a == triangle.b && triangle.b == triangle.c);
}

bool is_isosceles(triangle_t triangle)
{
  return is_triangle(triangle) && (triangle.a == triangle.b || triangle.a == triangle.c || triangle.b == triangle.c);
}

bool is_scalene(triangle_t triangle)
{
  return is_triangle(triangle) && (triangle.a != triangle.b && triangle.a != triangle.c && triangle.b != triangle.c);
}
