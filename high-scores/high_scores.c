#include "high_scores.h"

// Return the latest score.
int32_t latest(int32_t const * const scores, size_t const scores_len)
{
  if (scores_len == 0)
    return 0;

  return scores[scores_len - 1];
}

// Return the highest score.
int32_t personal_best(int32_t const * const scores, size_t const scores_len)
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
size_t personal_top_three(int32_t const * const scores,
                          size_t const scores_len, int32_t * const output)
{
  for (size_t i = 0; i < scores_len; i++)
  {
    if (scores[i] > output[0])
    {
      output[2] = output[1];
      output[1] = output[0];
      output[0] = scores[i];
    }
    else if (scores[i] > output[1])
    {
      output[2] = output[1];
      output[1] = scores[i];
    }
    else if (scores[i] > output[2])
      output[2] = scores[i];
  }

  return scores_len > 3 ? 3 : scores_len;
}
