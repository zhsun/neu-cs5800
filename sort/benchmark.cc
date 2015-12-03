#include <algorithm>
#include <cassert>
#include <chrono>
#include <cstddef>
#include <fstream>
#include <functional>
#include <iostream>
#include <vector>

#include "sort/counting_sort.hpp"
#include "sort/heap_sort.hpp"
#include "sort/merge_sort.hpp"
#include "sort/quick_sort.hpp"
#include "sort/radix_sort.hpp"
#include "sort/sort.hpp"

using namespace std;

const size_t kCount = 1000000;
const char kRandomIntFilename[] = "datafile/random_int_1m";
const char kRandomInt3dFilename[] = "datafile/random_int3d_1m";

template<typename T>
void ReadData(const char* filename, size_t elem_count, vector<T>& data) {
  ifstream f(filename, ifstream::in);
  assert(f.is_open());
  data.reserve(elem_count);
  T elem;
  while (f >> elem) {
    data.push_back(elem);
  }
  f.close();
  assert(data.size() == elem_count);
}

template<typename T>
bool IsSorted(const vector<T>& data) {
  for (size_t i = 1; i < data.size(); ++i) {
    if (data[i-1] > data[i]) return false;
  }
  return true;
}

void MeasureTime(std::function<void()> f) {
  using namespace std::chrono;
  auto start = high_resolution_clock::now();
  f();
  auto end = high_resolution_clock::now();
  cout << "Time used: " 
       << duration_cast<milliseconds>(end - start).count()
       << " milliseconds. " << endl;
}

void BenchmarkOnInt() {
  vector<int> data;
  ReadData(kRandomIntFilename, kCount, data);

  cout << "MergeSort" << endl;
  vector<int> input = data;
  assert(!IsSorted(input));
  MeasureTime([&input]() { MergeSort(input.begin(), input.end()); });
  assert(IsSorted(input));

  cout << "HeapSort" << endl;
  input = data;
  assert(!IsSorted(input));
  MeasureTime([&input]() { HeapSort(input.begin(), input.end()); });
  assert(IsSorted(input));

  cout << "QuickSort" << endl;
  input = data;
  assert(!IsSorted(input));
  MeasureTime([&input]() { QuickSort(input.begin(), input.end()); });
  assert(IsSorted(input));

  cout << "Sort" << endl;
  input = data;
  assert(!IsSorted(input));
  MeasureTime([&input]() { Sort(input.begin(), input.end()); });
  assert(IsSorted(input));

  cout << "std::sort" << endl;
  input = data;
  assert(!IsSorted(input));
  MeasureTime([&input]() { sort(input.begin(), input.end()); });
  assert(IsSorted(input));

  cout << "std::stable_sort" << endl;
  input = data;
  assert(!IsSorted(input));
  MeasureTime([&input]() { std::stable_sort(input.begin(), input.end()); });
  assert(IsSorted(input));
}

void BenchmarkOnInt3d() {
  vector<int> data;
  ReadData(kRandomInt3dFilename, kCount, data);

  cout << "MergeSort" << endl;
  vector<int> input = data;
  assert(!IsSorted(input));
  MeasureTime([&input]() { MergeSort(input.begin(), input.end()); });
  assert(IsSorted(input));

  cout << "HeapSort" << endl;
  input = data;
  assert(!IsSorted(input));
  MeasureTime([&input]() { HeapSort(input.begin(), input.end()); });
  assert(IsSorted(input));

  cout << "QuickSort" << endl;
  input = data;
  assert(!IsSorted(input));
  MeasureTime([&input]() { QuickSort(input.begin(), input.end()); });
  assert(IsSorted(input));

  cout << "Sort" << endl;
  input = data;
  assert(!IsSorted(input));
  MeasureTime([&input]() { Sort(input.begin(), input.end()); });
  assert(IsSorted(input));

  cout << "CountingSort" << endl;
  input = data;
  assert(!IsSorted(input));
  MeasureTime([&input]() {
      CountingSort(input.begin(), input.end(), 
		   [](int x) { return x; }, 1000);
    });
  assert(IsSorted(input));

  cout << "RadixSort" << endl;
  input = data;
  assert(!IsSorted(input));
  MeasureTime([&input]() { RadixSort(input.begin(), input.end(), 3); });
  assert(IsSorted(input));

  cout << "std::sort" << endl;
  input = data;
  assert(!IsSorted(input));
  MeasureTime([&input]() { std::sort(input.begin(), input.end()); });
  assert(IsSorted(input));

  cout << "std::stable_sort" << endl;
  input = data;
  assert(!IsSorted(input));
  MeasureTime([&input]() { std::stable_sort(input.begin(), input.end()); });
  assert(IsSorted(input));
}

int main() {
  cout << "Benchmark on 1M random integers." << endl;
  BenchmarkOnInt();
  cout << endl;

  cout << "Benchmark on 1M random 3 digit-integers." << endl;
  BenchmarkOnInt3d();
  cout << endl;
  return 0;
}
