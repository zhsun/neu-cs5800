#include "gmock/gmock.h"
#include "edit_distance.h"

using namespace std;
using namespace testing;

TEST(EditDistanceTest, BothEmpty) {
  EXPECT_THAT(EditDistance("", ""), Eq(0));
}

TEST(EditDistanceTest, OneEmpty) {
  string str = "xyz";
  EXPECT_THAT(EditDistance(str, ""), Eq(str.size()));
  EXPECT_THAT(EditDistance("", str), Eq(str.size()));
}

TEST(EditDistanceTest, GeneralCase) {
  EXPECT_THAT(EditDistance("exponential", "polynomial"), Eq(6));
}
