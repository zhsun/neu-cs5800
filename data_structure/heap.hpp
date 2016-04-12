#ifndef DATA_STRUCTURE_HEAP_H_
#define DATA_STRUCTURE_HEAP_H_

#include <cassert>
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
    size_t i = data_.size() - 1;
    while (HasParent(i) &&
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
  void Heapify(size_t cur) {
    size_t largest = cur;
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

  size_t ParentIndex(size_t cur) const {
    assert(HasParent(cur));
    return (cur - 1) / 2;
  }

  bool HasParent(size_t cur) const {
    return cur != 0;
  }

  size_t LeftChildIndex(size_t cur) const {
    return cur * 2 + 1;
  }

  bool HasLeftChild(size_t cur) const {
    return LeftChildIndex(cur) < data_.size();
  }

  size_t RightChildIndex(size_t cur) const {
    return cur * 2 + 2;
  }

  bool HasRightChild(size_t cur) const {
    return RightChildIndex(cur) < data_.size();
  }

  std::vector<T> data_;
};

#endif  // DATA_STRUCTURE_HEAP_H_
