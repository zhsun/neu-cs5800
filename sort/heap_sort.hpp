#ifndef SORT_HEAPSORT_H_
#define SORT_HEAPSORT_H_

#include <algorithm>
#include <functional>
#include <iterator>

template<typename RandomAccessIterator, typename Compare>
void HeapSort(RandomAccessIterator begin, RandomAccessIterator end, 
	      Compare comp) {
  std::make_heap(begin, end, comp);
  for (RandomAccessIterator itr = end; itr != begin; --itr) {
    std::pop_heap(begin, itr, comp);
  }
}

template<typename RandomAccessIterator>
void HeapSort(RandomAccessIterator begin, RandomAccessIterator end) {
  using value_type =
    typename std::iterator_traits<RandomAccessIterator>::value_type;
  HeapSort(begin, end, std::less<value_type>());
}

#endif  // SORT_HEAPSORT_H_
