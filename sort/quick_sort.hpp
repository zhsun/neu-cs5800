#ifndef SORT_QUICKSORT_H_
#define SORT_QUICKSORT_H_

#include <algorithm>
#include <functional>
#include <iterator>

template<typename RandomAccessIterator, typename Compare>
RandomAccessIterator
Partition(RandomAccessIterator begin, RandomAccessIterator end, Compare comp) {
  if (begin == end) return end;
  using value_type =
    typename std::iterator_traits<RandomAccessIterator>::value_type;
  value_type pivot = *begin;
  RandomAccessIterator last = begin;
  for (auto cur = std::next(begin); cur != end; ++cur) {
    if (comp(*cur, pivot)) {
      std::iter_swap(++last, cur);
    }
  }
  std::iter_swap(begin, last);
  return last;
}

template<typename RandomAccessIterator, typename Compare>
void QuickSort(RandomAccessIterator begin, RandomAccessIterator end,
	       Compare comp) {
  using difference_type =
    typename std::iterator_traits<RandomAccessIterator>::difference_type;
  difference_type n = end - begin;
  if (n == 0 || n == 1) return;
  RandomAccessIterator p = Partition(begin, end, comp);
  QuickSort(begin, p, comp);
  QuickSort(std::next(p), end, comp);
}

template<typename RandomAccessIterator>
void QuickSort(RandomAccessIterator begin, RandomAccessIterator end) {
  using value_type =
    typename std::iterator_traits<RandomAccessIterator>::value_type;
  QuickSort(begin, end, std::less<value_type>());
}

#endif  // SORT_QUICKSORT_H_
