#include "gmock/gmock.h"
#include "knapsack.h"

using namespace std;
using namespace testing;

class KnapsackTest : public Test {
public:
  KnapsackTest() {
    items.emplace_back(30, 6);
    items.emplace_back(14, 3);
    items.emplace_back(16, 4);
    items.emplace_back(9, 2);
  }

  vector<Item> items;
};

TEST_F(KnapsackTest, RepeatableTooBigItems) {
  EXPECT_THAT(Knapsack(items, 1, true), Eq(0));
}

TEST_F(KnapsackTest, RepeatableMutipleOfMostValuableItem) {
  int m = 20;
  // The first item in the list has the most value/weight ratio.
  EXPECT_THAT(Knapsack(items, m * 6, true), Eq(m * 30));
}

TEST_F(KnapsackTest, RepeatableGeneralCase) {
  // Should take 1 item 1, and 2 item 4.
  EXPECT_THAT(Knapsack(items, 10, true), Eq(30 + 2 * 9));
}

TEST_F(KnapsackTest, NonrepeatableTooBigItems) {
  EXPECT_THAT(Knapsack(items, 1, false), Eq(0));
}

TEST_F(KnapsackTest, NonrepeatableVeryBigKnapsack) {
  // Since each item only has one copy, so can only take so much.
  EXPECT_THAT(Knapsack(items, 100, false), Eq(30 + 14 + 16 + 9));
}

TEST_F(KnapsackTest, NonrepeatableGeneralCase) {
  // Should take item 1 and item 3.
  EXPECT_THAT(Knapsack(items, 10, false), Eq(30 + 16));
}
