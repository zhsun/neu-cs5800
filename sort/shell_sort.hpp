#ifndef SORT_SHELLSORT_H_
#define SORT_SHELLSORT_H_

#include <functional>
#include <iterator>

template<typename RandomAccessIterator, typename Compare>
void ShellSort(RandomAccessIterator begin, RandomAccessIterator end,
	       Compare comp) {
  using difference_type =
    typename std::iterator_traits<RandomAccessIterator>::difference_type;
  difference_type n = end - begin;
  difference_type h = 1;
  while (3 * h < n) h = 3 * h + 1;
  for (; h > 0; h /= 3) {
    for (auto i = begin + h; i < end; ++i) {
      for (auto j = i; j - h >= begin && comp(*j, *(j - h)); j -= h) {
	std::iter_swap(j, j - h);
      }
    }
  }
}

template<typename RandomAccessIterator>
void ShellSort(RandomAccessIterator begin, RandomAccessIterator end) {
  using value_type =
    typename std::iterator_traits<RandomAccessIterator>::value_type;
  ShellSort(begin, end, std::less<value_type>());
}

#endif  // SORT_SHELLSORT_H_
