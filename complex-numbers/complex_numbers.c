#include "complex_numbers.h"
#include <math.h>

double c_real(complex_t const x) { return x.real; }

double c_imag(complex_t const x) { return x.imag; }

complex_t c_add(complex_t const a, complex_t const b)
{
  return (complex_t){.real = c_real(a) + c_real(b),
                     .imag = c_imag(a) + c_imag(b)};
}

complex_t c_sub(complex_t const a, complex_t const b)
{
  return (complex_t){.real = c_real(a) - c_real(b),
                     .imag = c_imag(a) - c_imag(b)};
}

complex_t c_mul(complex_t const a, complex_t const b)
{
  return (complex_t){.real = (c_real(a) * c_real(b) - c_imag(a) * c_imag(b)),
                     .imag = (c_imag(a) * c_real(b) + c_real(a) * c_imag(b))};
}

complex_t c_div(complex_t const a, complex_t const b)
{
  return (complex_t){.real = (c_real(a) * c_real(b) + c_imag(a) * c_imag(b)) /
                             (pow(c_real(b), 2) + pow(c_imag(b), 2)),
                     .imag = (c_imag(a) * c_real(b) - c_real(a) * c_imag(b)) /
                             (pow(c_real(b), 2) + pow(c_imag(b), 2))};
}

double c_abs(complex_t const x)
{
  return sqrt(pow(c_real(x), 2) + pow(c_imag(x), 2));
}

complex_t c_conjugate(complex_t const x)
{
  return (complex_t){.real = c_real(x), .imag = -c_imag(x)};
}

complex_t c_exp(complex_t const x)
{
  return (complex_t){.real = exp(c_real(x)) * cos(c_imag(x)),
                     .imag = exp(c_real(x)) * sin(c_imag(x))};
}
