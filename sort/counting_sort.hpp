#ifndef SORT_COUNTINGSORT_H_
#define SORT_COUNTINGSORT_H_

#include <iterator>
#include <vector>

// KeyFn is a functor that maps element to int. 'k' specifies the
// range of key_fn(element). [0...k].
template<typename RandomAccessIterator, typename KeyFn>
void CountingSort(RandomAccessIterator begin, RandomAccessIterator end,
		  KeyFn key_fn, int k) {
  using value_type =
    typename std::iterator_traits<RandomAccessIterator>::value_type;
  std::vector<value_type> aux(begin, end);
  std::vector<int> count(k+1, 0);
  for (const auto& elem : aux) {
    ++count[key_fn(elem)];
  }
  for (size_t i = 1; i < count.size(); ++i) {
    count[i] += count[i-1];
  }
  for (auto itr = aux.rbegin(); itr != aux.rend(); ++itr) {
    *(begin + count[key_fn(*itr)]-- - 1) = *itr;
  }
}

#endif  // SORT_COUNTINGSORT_H_
