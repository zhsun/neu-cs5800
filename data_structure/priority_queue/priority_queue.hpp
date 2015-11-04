#include <cassert>
#include <functional>
#include <unordered_map>
#include <utility>
#include <vector>

// This priority queue is implimented based on heap data
// structure. Besides the Insert, Delete, GetMax operations from heap,
// it also supports Update methods to update the priority of an
// existing element. Therefore, internally it uses a map to keep track
// of the mapping between elements and their priority location in the
// heap.
//
// The template type parameter T should be a light weight type (small
// copy cost), which represents the "ID" of what your objects. In
// Dijkstra's and Prim's algorithms, this T should be vertex id. The
// other template parameter P is for priority. Usually it should be
// int or double.
template<typename T,  // Type of elements
	 typename P,  // Type of priroity
	 typename Comparator = std::less<P>>
class PriorityQueue {
 public:
  struct QueueElem {
    QueueElem(const T& t, const P& p) : t_(t), p_(p) { }
    T t_;
    P p_;
  };

  PriorityQueue() : priorities_(), elem_index_map_() { }

  bool IsEmpty() const {
    return priorities_.empty();
  }

  T GetMax() const {
    return priorities_[0].t_;
  }

  void Insert(const T& elem, const P& priority) {
    // *elem* should be new element.
    assert(elem_index_map_.find(elem) == elem_index_map_.end());
    priorities_.emplace_back(elem, priority);
    size_t cur = priorities_.size() - 1;
    elem_index_map_[elem] = cur;
    BubbleUp(cur);
  }

  void Delete() {
    assert(!priorities_.empty());
    Swap(0, priorities_.size() - 1);
    priorities_.pop_back();
    Heapify(0);
  }

  void Update(const T& elem, const P& new_priority) {
    // *elem* should be an existing element.
    assert(elem_index_map_.find(elem) != elem_index_map_.end());
    size_t idx = elem_index_map_[elem];
    P old_priority = priorities_[idx].p_;
    priorities_[idx].p_ = new_priority;
    if (Comparator()(old_priority, new_priority)) {
      BubbleUp(idx);
    } else {
      Heapify(idx);
    }
  }

 private:
  // Swap cooresponding elements in priorities_, and update index map
  // properly.
  void Swap(size_t a, size_t b) {
    elem_index_map_[priorities_[a].t_] = b;
    elem_index_map_[priorities_[b].t_] = a;
    std::swap(priorities_[a], priorities_[b]);
  }

  void BubbleUp(size_t cur) {
    while (cur != Parent(cur) &&
	   !Comparator()(priorities_[cur].p_,
			 priorities_[Parent(cur)].p_)) {
      Swap(cur, Parent(cur));
      cur = Parent(cur);
    }
  }

  void Heapify(size_t cur) {
    size_t largest = cur;
    if (HasLeftChild(cur) &&
	!Comparator()(priorities_[LeftChild(cur)].p_,
		      priorities_[largest].p_)) {
      largest = LeftChild(cur);
    }
    if (HasRightChild(cur) &&
	!Comparator()(priorities_[RightChild(cur)].p_,
		      priorities_[largest].p_)) {
      largest = RightChild(cur);
    }
    if (largest != cur) {
      Swap(cur, largest);
      Heapify(largest);
    }
  }

  size_t LeftChild(size_t cur) const {
    return 2 * cur + 1;
  }

  bool HasLeftChild(size_t cur) const {
    return LeftChild(cur) < priorities_.size();
  }

  size_t RightChild(size_t cur) const {
    return 2 * cur + 2;
  }

  bool HasRightChild(size_t cur) const {
    return RightChild(cur) < priorities_.size();
  }

  size_t Parent(size_t cur) const {
    if (cur == 0) return 0;
    return (cur - 1) / 2;
  }

  // priorities_ is a vector of priorities values represented in heap
  // data structure.
  std::vector<QueueElem> priorities_;
  // elem_index_map_ is a map between elements of type T, and its
  // priority index in vector priorities_. E.g. if an element's index
  // is i, then priorities_[i] represents its priority value.
  std::unordered_map<T,size_t> elem_index_map_;
};
