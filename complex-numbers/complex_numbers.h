#ifndef COMPLEX_NUMBERS_H
#define COMPLEX_NUMBERS_H

typedef struct
{
  double real;
  double imag;
} complex_t;

double c_real(complex_t const x);
double c_imag(complex_t const x);
complex_t c_add(complex_t const a, complex_t const b);
complex_t c_sub(complex_t const a, complex_t const b);
complex_t c_mul(complex_t const a, complex_t const b);
complex_t c_div(complex_t const a, complex_t const b);
double c_abs(complex_t const x);
complex_t c_conjugate(complex_t const x);
complex_t c_exp(complex_t const x);

#endif
