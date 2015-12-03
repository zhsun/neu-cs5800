#ifndef SORT_SORT_H_
#define SORT_SORT_H_

#include <cassert>
#include <functional>
#include <iterator>
#include <utility>

template<typename RandomAccessIterator, typename Compare>
std::pair<RandomAccessIterator, RandomAccessIterator>
ThreeWayPartition(RandomAccessIterator begin, RandomAccessIterator end,
		  Compare less_than) {
  assert(begin != end);
  auto pivot = *begin;
  // Three parts: [begin,i], [i+1,j], [j+1,end).
  auto i = begin, j = begin;
  for (auto cur = std::next(begin); cur != end; ++cur) {
    if (*cur == pivot) std::iter_swap(++j, cur);
    else if (less_than(*cur, pivot)) {
      std::iter_swap(++j, cur);
      std::iter_swap(++i, j);
    }
  }
  std::iter_swap(begin, i);
  return std::make_pair(i, std::next(j));
}

template<typename RandomAccessIterator, typename Compare>
void Sort(RandomAccessIterator begin, RandomAccessIterator end,
	  Compare less_than) {
  auto n = end - begin;
  if (n < 2) return;
  auto itrs = ThreeWayPartition(begin, end, less_than);
  Sort(begin, itrs.first, less_than);
  Sort(itrs.second, end, less_than);
}

// *Sort* is a refined version of QuickSort. It assumes elements in
// *the range [begin,end) have operator '<' and '==' implemented.
template<typename RandomAccessIterator>
void Sort(RandomAccessIterator begin, RandomAccessIterator end) {
  using value_type =
    typename std::iterator_traits<RandomAccessIterator>::value_type;
  Sort(begin, end, std::less<value_type>());
}

#endif  // SORT_SORT_H_
