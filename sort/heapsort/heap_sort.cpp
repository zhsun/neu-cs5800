#include "data_structure/heap/cpp/heap_function.hpp"
#include "sort/heapsort/heap_sort.h"

void Heapsort(std::vector<int>& arr) {
  heap_make(arr);
  for (int i = arr.size(); i > 0; i--) {
    heap_delete(arr, i);
  }
}
