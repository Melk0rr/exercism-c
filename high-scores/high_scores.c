#include "high_scores.h"
#include <stddef.h>
#include <stdint.h>

// Return the latest score.
int32_t latest(const int32_t *scores, size_t scores_len)
{
  if (scores_len == 0)
    return 0;

  return scores[scores_len - 1];
}

// Return the highest score.
int32_t personal_best(const int32_t *scores, size_t scores_len)
{
  if (scores_len == 0)
    return 0;

  int32_t best = scores[0];
  for (size_t i = 1; i < scores_len; i++)
    if (scores[i] > best)
      best = scores[i];

  return best;
}

// Write the highest scores to `output` (in non-ascending order).
// Return the number of scores written.
size_t personal_top_three(const int32_t *scores, size_t scores_len, int32_t *output)
{
  size_t output_len = 0;
  for (size_t i = 0; i < scores_len; i++) {
    if (scores[i] > output[0])
    {
      output[2] = output[1];
      output[1] = output[0];
      output[0] = scores[i];

    } else if (scores[i] > output[1]) {
      output[2] = output[1];
      output[1] = scores[i];

    } else if (scores[i] > output[2])
      output[2] = scores[i];

    else
      continue;

    if (output_len < 3)
      ++output_len;
  }

  return output_len;
}
