#include <cstdlib>

#include <functional>
#include <vector>

namespace {
  // Helper functions.
  size_t parent(size_t pos) {
    return abs(pos - 1) / 2;
  }

  size_t left(size_t pos) {
    return pos * 2 + 1;
  }

  size_t right(size_t pos) {
    return pos * 2 + 2;
  }

  bool has_parent(size_t pos) {
    return parent(pos) != pos;
  }

  bool has_left(size_t pos, size_t heap_size) {
    return left(pos) < heap_size;
  }

  bool has_right(size_t pos, size_t heap_size) {
    return right(pos) < heap_size;
  }

  template<typename T, typename Cmp = std::less<T> >
  void heapify(std::vector<T>& arr, size_t heap_size, size_t pos) {
    int largest = pos;
    if (has_left(pos, heap_size) &&
	!Cmp()(arr[left(pos)], arr[largest])) {
      largest = left(pos);
    }
    if (has_right(pos, heap_size) &&
	!Cmp()(arr[right(pos)], arr[largest])) {
      largest = right(pos);
    }
    if (largest != pos) {
      std::swap(arr[pos], arr[largest]);
      heapify(arr, heap_size, largest);
    }
  }
}

template<typename T, typename Cmp = std::less<T> >
void heap_make(std::vector<T>& arr) {
  int middle = arr.size() / 2 - 1;
  for (int i = middle; i >= 0; --i) {
    heapify(arr, arr.size(), i);
  }
}

template<typename T, typename Cmp = std::less<T> >
void heap_insert(std::vector<T>& arr, size_t heap_size, const T& val) {
  arr[heap_size++] = val;
  int i = heap_size - 1;
  while (has_parent(i) &&
	 !Cmp()(arr[i], arr[parent(i)])) {
    std::swap(arr[i], arr[parent(i)]);
    i = parent(i);
  }
}

template<typename T, typename Cmp = std::less<T> >
void heap_delete(std::vector<T>& arr, size_t heap_size) {
  std::swap(arr[0], arr[--heap_size]);
  heapify(arr, heap_size, 0);
}
