#include <unordered_map>
#include <vector>
#include "gmock/gmock.h"

using namespace std;
using namespace testing;

// In this version of knapsack problem, each item has only one copy,
struct Item {
  Item(int v, int w) : value(v), weight(w) { }

  int value;
  int weight;
};

// Knapsack function returns the max value. *items* is a list of
// avaiable items, and *W* is the knapsack capacity.
int KnapsackRec(const vector<Item>& items,
		int W,  // total capacity
		int k,  // {1,2,...,k} items can choose. 1-based index.
		unordered_map<int,int>* dp) {
  if (dp->find(W) != dp->end()) {
    return (*dp)[W];
  }
  if (k == 0) {
    // Nothing can pick.
    return 0;
  }
  const Item& item = items[k-1];
  // Solution for not taking kth item.
  int value = KnapsackRec(items, W, k-1, dp);
  if (item.weight <= W) {
    // Solution for taking kth item.
    int cur_value = item.value + KnapsackRec(items, W-item.weight, k-1, dp);
    if (cur_value > value) {
      value = cur_value;
    }
  }
  (*dp)[W] = value;
  return value;
}

int Knapsack(const vector<Item>& items, int W) {
  unordered_map<int,int> dp;
  return KnapsackRec(items, W, items.size(), &dp);
}

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

TEST_F(KnapsackTest, TooBigItems) {
  EXPECT_THAT(Knapsack(items, 1), Eq(0));
}

TEST_F(KnapsackTest, VeryBigKnapsack) {
  // Since each item only has one copy, so can only take so much.
  EXPECT_THAT(Knapsack(items, 100), Eq(30 + 14 + 16 + 9));
}

TEST_F(KnapsackTest, GeneralCase) {
  // Should take item 1 and item 3.
  EXPECT_THAT(Knapsack(items, 10), Eq(30 + 16));
}
