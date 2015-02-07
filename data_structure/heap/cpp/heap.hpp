#include <cstdlib>

#include <algorithm>
#include <functional>
#include <initializer_list>
#include <vector>

// A max heap (using Cmp operator).
template<typename T, typename Cmp = std::less<T>>
class Heap {
public:
  Heap(std::initializer_list<T> l) : data_(l) {
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
      std::swap(data_[i], data_[ParentIndex(i)]);
      i = ParentIndex(i);
    }
  }

  void Delete() {
    std::swap(data_[0], data_[data_.size()-1]);
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
      std::swap(data_[cur], data_[largest]);
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

  std::vector<T> data_;
};
