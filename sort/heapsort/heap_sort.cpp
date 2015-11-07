#include "data_structure/heap/heap_function.hpp"
#include "heap_sort.h"

void Heapsort(std::vector<int>& arr) {
  heap_make(arr);
  for (size_t i = arr.size(); i > 0; i--) {
    heap_delete(arr, i);
  }
}
