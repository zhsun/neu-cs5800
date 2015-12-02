#ifndef SORT_SELECTIONSORT_H_
#define SORT_SELECTIONSORT_H_

#include <functional>
#include <iterator>
#include <utility>

template<typename RandomAccessIterator, typename Compare>
void SelectionSort(RandomAccessIterator begin, 
		   RandomAccessIterator end, 
		   Compare comp) {
  for (RandomAccessIterator i = begin; i != end; ++i) {
    RandomAccessIterator smallest = i;
    for (RandomAccessIterator j = std::next(i); j != end; ++j) {
      if (comp(*j, *smallest)) {
	smallest = j;
      }
    }
    std::swap(*i, *smallest);
  }
}

template<typename RandomAccessIterator>
void SelectionSort(RandomAccessIterator begin, RandomAccessIterator end) {
  using value_type = 
    typename std::iterator_traits<RandomAccessIterator>::value_type;
  SelectionSort(begin, end, std::less<value_type>());
}

#endif  // SORT_SELECTIONSORT_H_
