#ifndef SORT_MERGESORT_H_
#define SORT_MERGESORT_H_

#include <algorithm>
#include <functional>
#include <iterator>
#include <vector>

template<typename RandomAccessIterator, typename Compare>
void MergeSort(RandomAccessIterator begin, RandomAccessIterator end,
	       Compare comp) {
  using difference_type =
    typename std::iterator_traits<RandomAccessIterator>::difference_type;
  difference_type n = end - begin;
  if (n < 2) return;
  RandomAccessIterator middle = std::next(begin, n / 2);
  MergeSort(begin, middle, comp);
  MergeSort(middle, end, comp);
  using value_type =
    typename std::iterator_traits<RandomAccessIterator>::value_type;
  std::vector<value_type> aux(n);
  std::merge(begin, middle, middle, end, aux.begin(), comp);
  std::copy(aux.begin(), aux.end(), begin);
}

template<typename RandomAccessIterator>
void MergeSort(RandomAccessIterator begin, RandomAccessIterator end) {
  using value_type = 
    typename std::iterator_traits<RandomAccessIterator>::value_type;
  MergeSort(begin, end, std::less<value_type>());
}

template<typename RandomAccessIterator, typename Compare>
void MergeSortBottomUp(RandomAccessIterator begin,
		       RandomAccessIterator end,
		       Compare comp) {
  using difference_type =
    typename std::iterator_traits<RandomAccessIterator>::difference_type;
  difference_type n = end - begin;
  if (n < 2) return;
  using value_type =
    typename std::iterator_traits<RandomAccessIterator>::value_type;
  std::vector<value_type> aux(n);
  for (difference_type len = 1; len < n; len += len) {
    for (auto b = begin; b + len < end; b += 2 * len) {
      auto b1 = b, e1 = b1 + len;
      auto b2 = b + len, e2 = std::min(b2 + len, end);
      std::merge(b1, e1, b2, e2, aux.begin(), comp);
      std::copy(aux.begin(), aux.begin() + (e2 - b1), b);
    }
  }
}

template<typename RandomAccessIterator>
void MergeSortBottomUp(RandomAccessIterator begin,
		       RandomAccessIterator end) {
  using value_type =
    typename std::iterator_traits<RandomAccessIterator>::value_type;
  MergeSortBottomUp(begin, end, std::less<value_type>());
}

#endif  // SORT_MERGESORT_H_
