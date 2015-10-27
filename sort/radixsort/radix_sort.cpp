#include <vector>
#include "radix_sort.h"
#include "sort/countingsort/counting_sort.hpp"

// digits means the number of digits for ints in arr.
void radix_sort(std::vector<int>& arr, int digits) {
  for (int i = 0; i < digits; i++) {
    // key_fn will extract the ith digit (0-base) of a given int.
    auto key_fn = [i](int e) {
      for (int pos = i; pos > 0; pos--) e /= 10;
      return e % 10;
    };
    std::vector<int> out;
    counting_sort(arr, out, 9, key_fn);
    arr.swap(out);
  }
}
