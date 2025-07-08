#ifndef HIGH_SCORES_H
#define HIGH_SCORES_H

#include <stddef.h>
#include <stdint.h>

/// Return the latest score.
int32_t latest(int32_t const * const scores, size_t const scores_len);

/// Return the highest score.
int32_t personal_best(int32_t const * const scores,
                      size_t const scores_len);

/// Write the highest scores to `output` (in non-ascending order).
/// Return the number of scores written.
size_t personal_top_three(int32_t const * const scores, size_t const scores_len,
                          int32_t * const output);

#endif
