#ifndef SORT_RADIXSORT_H_
#define SORT_RADIXSORT_H_

#include <cstddef>
#include <iterator>
#include "sort/counting_sort.hpp"

template<typename RandomAccessIterator>
void RadixSort(RandomAccessIterator begin, RandomAccessIterator end,
	       size_t digits) {
  using value_type =
    typename std::iterator_traits<RandomAccessIterator>::value_type;
  for (size_t d = 0; d < digits; ++d) {
    auto key_fn = [d](value_type v) {
      for (size_t i = 0; i < d; ++i) v /= 10;
      return v % 10;
    };
    CountingSort(begin, end, key_fn, 9);
  }
}

#endif  // SORT_RADIXSORT_H_
