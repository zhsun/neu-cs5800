#ifndef SORT_INSERTIONSORT_H_
#define SORT_INSERTIONSORT_H_

#include <functional>
#include <iterator>
#include <utility>

template<typename RandomeAccessIterator, typename Compare>
void InsertionSort(RandomeAccessIterator begin,
		   RandomeAccessIterator end,
		   Compare comp) {
  if (begin == end) return;
  for (RandomeAccessIterator i = std::next(begin); i != end; ++i) {
    for (RandomeAccessIterator j = i; j != begin; --j) {
      RandomeAccessIterator pre = std::prev(j);
      if (comp(*pre, *j)) break;
      std::swap(*pre, *j);
    }
  }
}

template<typename RandomeAccessIterator>
void InsertionSort(RandomeAccessIterator begin, RandomeAccessIterator end) {
  using value_type =
    typename std::iterator_traits<RandomeAccessIterator>::value_type;
  InsertionSort(begin, end, std::less<value_type>());
}

#endif  // SORT_INSERTIONSORT_H_
