#include <vector>
#include "gmock/gmock.h"
#include "radix_sort.h"

using namespace std;
using namespace testing;

TEST(QuicksortTest, GeneralCase) {
  vector<int> arr = {465,321,474,355,123,
                     777,919,134,221,756};
  radix_sort(arr, 3);
  EXPECT_THAT(arr, ElementsAre(123,134,221,321,355,
                               465,474,756,777,919));
}
