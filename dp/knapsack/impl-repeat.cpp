#include <unordered_map>
#include <vector>
#include "gmock/gmock.h"

using namespace std;
using namespace testing;

// In this version of knapsack problem, each item has infinite copies,
// e.g. one can repeatedly take one item.
struct Item {
  Item(int v, int w) : value(v), weight(w) { }

  int value;
  int weight;
};

// Knapsack function returns the max value. *items* is a list of
// avaiable items, and *W* is the knapsack capacity.
int KnapsackRec(const vector<Item>& items, int W, unordered_map<int,int>* dp) {
  if (dp->find(W) != dp->end()) {
    return (*dp)[W];
  }
  int value = 0;
  for (const Item& item : items) {
    if (item.weight <= W) {
      int cur_value = item.value + KnapsackRec(items, W-item.weight, dp);
      if (cur_value > value) {
	value = cur_value;
      }
    }
  }
  (*dp)[W] = value;
  return value;
}

int Knapsack(const vector<Item>& items, int W) {
  unordered_map<int,int> dp;
  return KnapsackRec(items, W, &dp);
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

TEST_F(KnapsackTest, MutipleOfMostValuableItem) {
  int m = 20;
  // The first item in the list has the most value/weight ratio.
  EXPECT_THAT(Knapsack(items, m * 6), Eq(m * 30));
}

TEST_F(KnapsackTest, GeneralCase) {
  // Should take 1 item 1, and 2 item 4.
  EXPECT_THAT(Knapsack(items, 10), Eq(30 + 2 * 9));
}
