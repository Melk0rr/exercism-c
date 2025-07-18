#ifndef SUBLIST_H
#define SUBLIST_H

#include <stddef.h>

typedef enum
{
  EQUAL,
  UNEQUAL,
  SUBLIST,
  SUPERLIST
} comparison_result_t;

comparison_result_t check_lists(int const * const list_to_compare,
                                int const * const base_list,
                                size_t const list_to_compare_element_count,
                                size_t const base_list_element_count);

#endif
