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
#include "sort/shell_sort.hpp"
#include "sort/sort.hpp"

using namespace std;

const size_t kCount = 1000000;
const char kRandomIntFilename[] = "datafile/random_int_1m";
const char kRandomInt3dFilename[] = "datafile/random_int3d_1m";
const char kRandomFloatFilename[] = "datafile/random_float_1m";

void BenchmarkOnInt();
void BenchmarkOnInt3d();
void BenchmarkOnFloat();

int main() {
  cout << "Benchmark on 1M random integers." << endl;
  BenchmarkOnInt();
  cout << endl;

  cout << "Benchmark on 1M random 3 digit-integers." << endl;
  BenchmarkOnInt3d();
  cout << endl;

  cout << "Benchmark on 1M random floating numbers." << endl;
  BenchmarkOnFloat();
  cout << endl;
  return 0;
}

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

void MeasureTime(std::function<void()> f) {
  using namespace std::chrono;
  auto start = high_resolution_clock::now();
  f();
  auto end = high_resolution_clock::now();
  cout << duration_cast<milliseconds>(end - start).count()
       << " milliseconds. " << endl;
}

void BenchmarkOnInt() {
  vector<int> data;
  ReadData(kRandomIntFilename, kCount, data);

  cout << "MergeSort: ";
  vector<int> input = data;
  assert(!is_sorted(input.begin(), input.end()));
  MeasureTime([&input]() { MergeSort(input.begin(), input.end()); });
  assert(is_sorted(input.begin(), input.end()));

  cout << "MergeSortBottomUp: ";
  input = data;
  assert(!is_sorted(input.begin(), input.end()));
  MeasureTime([&input]() { MergeSortBottomUp(input.begin(), input.end()); });
  assert(is_sorted(input.begin(), input.end()));

  cout << "HeapSort: ";
  input = data;
  assert(!is_sorted(input.begin(), input.end()));
  MeasureTime([&input]() { HeapSort(input.begin(), input.end()); });
  assert(is_sorted(input.begin(), input.end()));

  cout << "QuickSort: ";
  input = data;
  assert(!is_sorted(input.begin(), input.end()));
  MeasureTime([&input]() { QuickSort(input.begin(), input.end()); });
  assert(is_sorted(input.begin(), input.end()));

  cout << "Sort: ";
  input = data;
  assert(!is_sorted(input.begin(), input.end()));
  MeasureTime([&input]() { Sort(input.begin(), input.end()); });
  assert(is_sorted(input.begin(), input.end()));

  cout << "std::sort: ";
  input = data;
  assert(!is_sorted(input.begin(), input.end()));
  MeasureTime([&input]() { sort(input.begin(), input.end()); });
  assert(is_sorted(input.begin(), input.end()));

  cout << "std::stable_sort: ";
  input = data;
  assert(!is_sorted(input.begin(), input.end()));
  MeasureTime([&input]() { std::stable_sort(input.begin(), input.end()); });
  assert(is_sorted(input.begin(), input.end()));

  cout << "ShellSort: ";
  input = data;
  assert(!is_sorted(input.begin(), input.end()));
  MeasureTime([&input]() { ShellSort(input.begin(), input.end()); });
  assert(is_sorted(input.begin(), input.end()));
}

void BenchmarkOnInt3d() {
  vector<int> data;
  ReadData(kRandomInt3dFilename, kCount, data);

  cout << "MergeSort: ";
  vector<int> input = data;
  assert(!is_sorted(input.begin(), input.end()));
  MeasureTime([&input]() { MergeSort(input.begin(), input.end()); });
  assert(is_sorted(input.begin(), input.end()));

  cout << "MergeSortBottomUp: ";
  input = data;
  assert(!is_sorted(input.begin(), input.end()));
  MeasureTime([&input]() { MergeSortBottomUp(input.begin(), input.end()); });
  assert(is_sorted(input.begin(), input.end()));

  cout << "HeapSort: ";
  input = data;
  assert(!is_sorted(input.begin(), input.end()));
  MeasureTime([&input]() { HeapSort(input.begin(), input.end()); });
  assert(is_sorted(input.begin(), input.end()));

  cout << "QuickSort: ";
  input = data;
  assert(!is_sorted(input.begin(), input.end()));
  MeasureTime([&input]() { QuickSort(input.begin(), input.end()); });
  assert(is_sorted(input.begin(), input.end()));

  cout << "Sort: ";
  input = data;
  assert(!is_sorted(input.begin(), input.end()));
  MeasureTime([&input]() { Sort(input.begin(), input.end()); });
  assert(is_sorted(input.begin(), input.end()));

  cout << "std::sort: ";
  input = data;
  assert(!is_sorted(input.begin(), input.end()));
  MeasureTime([&input]() { std::sort(input.begin(), input.end()); });
  assert(is_sorted(input.begin(), input.end()));

  cout << "std::stable_sort: ";
  input = data;
  assert(!is_sorted(input.begin(), input.end()));
  MeasureTime([&input]() { std::stable_sort(input.begin(), input.end()); });
  assert(is_sorted(input.begin(), input.end()));

  cout << "CountingSort: ";
  input = data;
  assert(!is_sorted(input.begin(), input.end()));
  MeasureTime([&input]() {
      CountingSort(input.begin(), input.end(), 
		   [](int x) { return x; }, 1000);
    });
  assert(is_sorted(input.begin(), input.end()));

  cout << "RadixSort: ";
  input = data;
  assert(!is_sorted(input.begin(), input.end()));
  MeasureTime([&input]() { RadixSort(input.begin(), input.end(), 3); });
  assert(is_sorted(input.begin(), input.end()));

  cout << "ShellSort: ";
  input = data;
  assert(!is_sorted(input.begin(), input.end()));
  MeasureTime([&input]() { ShellSort(input.begin(), input.end()); });
  assert(is_sorted(input.begin(), input.end()));
}

void BenchmarkOnFloat() {
  vector<double> data;
  ReadData(kRandomFloatFilename, kCount, data);

  cout << "MergeSort: ";
  vector<double> input = data;
  assert(!is_sorted(input.begin(), input.end()));
  MeasureTime([&input]() { MergeSort(input.begin(), input.end()); });
  assert(is_sorted(input.begin(), input.end()));

  cout << "MergeSortBottomUp: ";
  input = data;
  assert(!is_sorted(input.begin(), input.end()));
  MeasureTime([&input]() { MergeSortBottomUp(input.begin(), input.end()); });
  assert(is_sorted(input.begin(), input.end()));

  cout << "HeapSort: ";
  input = data;
  assert(!is_sorted(input.begin(), input.end()));
  MeasureTime([&input]() { HeapSort(input.begin(), input.end()); });
  assert(is_sorted(input.begin(), input.end()));

  cout << "QuickSort: ";
  input = data;
  assert(!is_sorted(input.begin(), input.end()));
  MeasureTime([&input]() { QuickSort(input.begin(), input.end()); });
  assert(is_sorted(input.begin(), input.end()));

  cout << "Sort: ";
  input = data;
  assert(!is_sorted(input.begin(), input.end()));
  MeasureTime([&input]() { Sort(input.begin(), input.end()); });
  assert(is_sorted(input.begin(), input.end()));

  cout << "std::sort: ";
  input = data;
  assert(!is_sorted(input.begin(), input.end()));
  MeasureTime([&input]() { sort(input.begin(), input.end()); });
  assert(is_sorted(input.begin(), input.end()));

  cout << "std::stable_sort: ";
  input = data;
  assert(!is_sorted(input.begin(), input.end()));
  MeasureTime([&input]() { std::stable_sort(input.begin(), input.end()); });
  assert(is_sorted(input.begin(), input.end()));

  cout << "ShellSort: ";
  input = data;
  assert(!is_sorted(input.begin(), input.end()));
  MeasureTime([&input]() { ShellSort(input.begin(), input.end()); });
  assert(is_sorted(input.begin(), input.end()));
}
