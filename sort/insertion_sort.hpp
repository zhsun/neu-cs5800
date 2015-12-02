#ifndef SORT_INSERTIONSORT_H_
#define SORT_INSERTIONSORT_H_

#include <functional>
#include <iterator>
#include <utility>

template<typename RandomAccessIterator, typename Compare>
void InsertionSort(RandomAccessIterator begin,
		   RandomAccessIterator end,
		   Compare comp) {
  if (begin == end) return;
  for (RandomAccessIterator i = std::next(begin); i != end; ++i) {
    for (RandomAccessIterator j = i; j != begin; --j) {
      RandomAccessIterator pre = std::prev(j);
      if (comp(*pre, *j)) break;
      std::swap(*pre, *j);
    }
  }
}

template<typename RandomAccessIterator>
void InsertionSort(RandomAccessIterator begin, RandomAccessIterator end) {
  using value_type =
    typename std::iterator_traits<RandomAccessIterator>::value_type;
  InsertionSort(begin, end, std::less<value_type>());
}

#endif  // SORT_INSERTIONSORT_H_
