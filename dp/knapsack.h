#ifndef DP_KNAPSACK_H_
#define DP_KNAPSACK_H_

#include <vector>

struct Item {
  Item(int v, int w) : value(v), weight(w) { }

  int value;
  int weight;
};

// If allow_repeat is true, items can be reused infinitely many times.
// If allow_repeat is false, there is only one copy for each item.
int Knapsack(const std::vector<Item>& items, int W, bool allow_repeat);

#endif  // DP_KNAPSACK_H_
