#include <functional>
#include <initializer_list>
#include <vector>
#include "gmock/gmock.h"

using namespace std;
using namespace testing;

// A max heap (using Cmp operator).
template<typename T, typename Cmp = less<T>>
class Heap {
public:
  Heap(initializer_list<T> l) : data_(l) {
    if (!IsEmpty()) {
      BuildHeap();
    }
  }

  T GetMax() const {
    return data_[0];
  }

  bool IsEmpty() const {
    return data_.empty();
  }

  size_t Size() const {
    return data_.size();
  }

  void Insert(const T& value) {
    data_.push_back(value);
    int i = data_.size() - 1;
    while (i != ParentIndex(i) &&
	   !Cmp()(data_[i], data_[ParentIndex(i)])) {
      swap(data_[i], data_[ParentIndex(i)]);
      i = ParentIndex(i);
    }
  }

  void Delete() {
    swap(data_[0], data_[data_.size()-1]);
    data_.pop_back();
    if (!IsEmpty()) {
      Heapify(0);
    }
  }

private:
  void Heapify(int cur) {
    int largest = cur;
    if (HasLeftChild(cur) &&
	!Cmp()(data_[LeftChildIndex(cur)], data_[largest])) {
      largest = LeftChildIndex(cur);
    }
    if (HasRightChild(cur) &&
	!Cmp()(data_[RightChildIndex(cur)], data_[largest])) {
      largest = RightChildIndex(cur);
    }
    if (largest != cur) {
      swap(data_[cur], data_[largest]);
      Heapify(largest);
    }
  }

  void BuildHeap() {
    int middle = data_.size() / 2 - 1;
    for (int i = middle; i >=0; --i) {
      Heapify(i);
    }
  }

  int ParentIndex(int cur) const {
    // 0-based index.
    return abs(cur - 1) / 2;
  }

  int LeftChildIndex(int cur) const {
    return cur * 2 + 1;
  }

  bool HasLeftChild(int cur) const {
    return LeftChildIndex(cur) < data_.size();
  }

  int RightChildIndex(int cur) const {
    return cur * 2 + 2;
  }

  bool HasRightChild(int cur) const {
    return RightChildIndex(cur) < data_.size();
  }

  vector<T> data_;
};

TEST(HeapTest, MaxHeapStartEmpty) {
  Heap<int> heap({});
  EXPECT_THAT(heap.IsEmpty(), Eq(true));

  int n = 10;
  for (int i = 1; i <= n; i++) {
    heap.Insert(i);
  }
  for (int i = n; i >= 1; --i) {
    EXPECT_THAT(heap.GetMax(), Eq(i));
    heap.Delete();
  }
  EXPECT_THAT(heap.IsEmpty(), Eq(true));
}

TEST(HeapTest, MinHeapStartEmpty) {
  Heap<int, greater<int>> heap({});
  EXPECT_THAT(heap.IsEmpty(), Eq(true));

  int n = 10;
  for (int i = 1; i <= n; i++) {
    heap.Insert(i);
  }
  for (int i = 1; i <= n; ++i) {
    EXPECT_THAT(heap.GetMax(), Eq(i));
    heap.Delete();
  }
  EXPECT_THAT(heap.IsEmpty(), Eq(true));
}

TEST(HeapTest, HeapStartWithList) {
  Heap<int> heap({1,3,2,6,4,5});
  EXPECT_THAT(heap.IsEmpty(), Eq(false));
  for (int i = 6; i >= 1; --i) {
    EXPECT_THAT(heap.GetMax(), Eq(i));
    heap.Delete();
  }
  EXPECT_THAT(heap.IsEmpty(), Eq(true));
}
