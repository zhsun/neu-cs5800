#include <vector>
#include "gmock/gmock.h"

#include "sort/count/cpp/counting_sort.hpp"

using namespace std;
using namespace testing;

// digits means the number of digits for ints in arr.
void radix_sort(vector<int>& arr, int digits) {
  for (int i = 0; i < digits; i++) {
    // key_fn will extract the ith digit (0-base) of a given int.
    auto key_fn = [i](int e) {
      for (int pos = i; pos > 0; pos--) e /= 10;
      return e % 10;
    };
    vector<int> out;
    counting_sort(arr, out, 9, key_fn);
    arr.swap(out);
  }
}

TEST(QuicksortTest, GeneralCase) {
  vector<int> arr = {465,321,474,355,123,
                     777,919,134,221,756};
  radix_sort(arr, 3);
  EXPECT_THAT(arr, ElementsAre(123,134,221,321,355,
                               465,474,756,777,919));
}
