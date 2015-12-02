#ifndef SORT_HEAPSORT_H_
#define SORT_HEAPSORT_H_

#include <algorithm>
#include <functional>
#include <iterator>

template<typename RandomeAccessIterator, typename Compare>
void HeapSort(RandomeAccessIterator begin, RandomeAccessIterator end, 
	      Compare comp) {
  std::make_heap(begin, end, comp);
  for (RandomeAccessIterator itr = end; itr != begin; --itr) {
    std::pop_heap(begin, itr, comp);
  }
}

template<typename RandomeAccessIterator>
void HeapSort(RandomeAccessIterator begin, RandomeAccessIterator end) {
  using value_type =
    typename std::iterator_traits<RandomeAccessIterator>::value_type;
  HeapSort(begin, end, std::less<value_type>());
}

#endif  // SORT_HEAPSORT_H_
