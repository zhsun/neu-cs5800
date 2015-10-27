#include <vector>
#include "gmock/gmock.h"

#include "counting_sort.hpp"

using namespace std;
using namespace testing;

TEST(QuicksortTest, GeneralCase) {
  vector<int> A = {3,1,2,5,3,1,5,2,4};
  vector<int> B;
  counting_sort(A, B, 5, [](int a) -> int{ return a; });
  EXPECT_THAT(B, ElementsAre(1,1,2,2,3,3,4,5,5));
}
