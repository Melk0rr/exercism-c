#include "sublist.h"
#include <stdbool.h>

static bool is_sublist(int *list_to_compare, int *base_list, size_t list_to_compare_element_count,
                       size_t base_list_element_count)
{
  if (list_to_compare_element_count == 0)
    return true;

  if (list_to_compare_element_count > base_list_element_count)
    return false;

  for (size_t i = 0; i <= base_list_element_count - list_to_compare_element_count; i++)
  {
    size_t j = 0;
    while (j < list_to_compare_element_count && base_list[i + j] == list_to_compare[j])
      ++j;

    if (j == list_to_compare_element_count)
      return true;
  }

  return false;
}
comparison_result_t check_lists(int *list_to_compare, int *base_list, size_t list_to_compare_element_count,
                                size_t base_list_element_count)
{
  if (list_to_compare_element_count == base_list_element_count)
  {
    bool equal = true;
    for (size_t i = 0; i < base_list_element_count; i++)
    {
      if (list_to_compare[i] != base_list[i])
      {
        equal = false;
        break;
      }
    }

    if (equal)
      return EQUAL;
  }

  if (is_sublist(list_to_compare, base_list, list_to_compare_element_count, base_list_element_count))
    return SUBLIST;

  if (is_sublist(base_list, list_to_compare, base_list_element_count, list_to_compare_element_count))
    return SUPERLIST;

  return UNEQUAL;
}
