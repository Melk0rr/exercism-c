#include "complex_numbers.h"
#include <math.h>

complex_t c_add(complex_t a, complex_t b)
{
  // TODO: implement
  complex_t z = {.real = a.real, .imag = b.imag};
  return z;
}

complex_t c_sub(complex_t a, complex_t b)
{
  // TODO: implement
  complex_t z = {.real = a.real, .imag = b.imag};
  return z;
}

complex_t c_mul(complex_t a, complex_t b)
{
  // TODO: implement
  complex_t z = {.real = a.real, .imag = b.imag};
  return z;
}

complex_t c_div(complex_t a, complex_t b)
{
  // TODO: implement
  complex_t z = {.real = a.real, .imag = b.imag};
  return z;
}

double c_abs(complex_t x)
{
  // TODO: implement
  return x.real;
}

complex_t c_conjugate(complex_t x)
{
  // TODO: implement
  complex_t c = x;
  return c;
}

double c_real(complex_t x) { return x.real; }

double c_imag(complex_t x) { return x.imag; }

complex_t c_exp(complex_t x)
{
  // TODO: implement
  return x;
}
