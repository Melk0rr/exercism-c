#include "sublist.h"
#include <stdbool.h>

static bool is_sublist(int const * const list_to_compare,
                       int const * const base_list,
                       size_t const list_to_compare_element_count,
                       size_t const base_list_element_count)
{
  if (list_to_compare_element_count == 0)
    return true;
  if (list_to_compare_element_count > base_list_element_count)
    return false;

  for (size_t i = 0;
       i <= base_list_element_count - list_to_compare_element_count; i++)
  {
    size_t j = 0;
    while (j < list_to_compare_element_count &&
           base_list[i + j] == list_to_compare[j])
      ++j;

    if (j == list_to_compare_element_count)
      return true;
  }

  return false;
}

static bool is_equal(int const * const list_to_compare,
                     int const * const base_list,
                     size_t const list_to_compare_element_count,
                     size_t const base_list_element_count)
{
  if (list_to_compare_element_count != base_list_element_count)
    return false;

  bool equal = true;
  for (size_t i = 0; i < base_list_element_count; i++)
  {
    if (list_to_compare[i] != base_list[i])
    {
      equal = false;
      break;
    }
  }

  return equal;
}

comparison_result_t check_lists(int const * const list_to_compare,
                                int const * const base_list,
                                size_t const list_to_compare_element_count,
                                size_t const base_list_element_count)
{

  return is_equal(base_list, list_to_compare, base_list_element_count,
                  list_to_compare_element_count)
             ? EQUAL
         : is_sublist(list_to_compare, base_list,
                      list_to_compare_element_count, base_list_element_count)
             ? SUBLIST
         : is_sublist(base_list, list_to_compare, base_list_element_count,
                      list_to_compare_element_count)
             ? SUPERLIST
             : UNEQUAL;
}
