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
#include "util/timer.hpp"

using namespace std;

const size_t kCount = 1000000;
const char kRandomIntFilename[] = "sort/datafile/random_int_1m";
const char kRandomInt3dFilename[] = "sort/datafile/random_int3d_1m";
const char kRandomFloatFilename[] = "sort/datafile/random_float_1m";

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

void Run(const string& algorithm_name, std::function<void()> f) {
  cout << algorithm_name << ": ";
  auto time_used = MeasureTime<chrono::milliseconds>(f);
  cout << time_used.count() << " milliseconds." << endl;
}

void BenchmarkOnInt() {
  vector<int> data;
  ReadData(kRandomIntFilename, kCount, data);

  vector<int> input = data;
  assert(!is_sorted(input.begin(), input.end()));
  Run("MergeSort",
      [&input]() { MergeSort(input.begin(), input.end()); });
  assert(is_sorted(input.begin(), input.end()));

  input = data;
  assert(!is_sorted(input.begin(), input.end()));
  Run("MergeSortBottomUp",
      [&input]() { MergeSortBottomUp(input.begin(), input.end()); });
  assert(is_sorted(input.begin(), input.end()));

  input = data;
  assert(!is_sorted(input.begin(), input.end()));
  Run("HeapSort",
      [&input]() { HeapSort(input.begin(), input.end()); });
  assert(is_sorted(input.begin(), input.end()));

  input = data;
  assert(!is_sorted(input.begin(), input.end()));
  Run("QuickSort",
      [&input]() { QuickSort(input.begin(), input.end()); });
  assert(is_sorted(input.begin(), input.end()));

  input = data;
  assert(!is_sorted(input.begin(), input.end()));
  Run("Sort",
      [&input]() { Sort(input.begin(), input.end()); });
  assert(is_sorted(input.begin(), input.end()));

  input = data;
  assert(!is_sorted(input.begin(), input.end()));
  Run("std::sort",
      [&input]() { sort(input.begin(), input.end()); });
  assert(is_sorted(input.begin(), input.end()));

  input = data;
  assert(!is_sorted(input.begin(), input.end()));
  Run("std::stable_sort",
      [&input]() { std::stable_sort(input.begin(), input.end()); });
  assert(is_sorted(input.begin(), input.end()));

  input = data;
  assert(!is_sorted(input.begin(), input.end()));
  Run("ShellSort",
      [&input]() { ShellSort(input.begin(), input.end()); });
  assert(is_sorted(input.begin(), input.end()));
}

void BenchmarkOnInt3d() {
  vector<int> data;
  ReadData(kRandomInt3dFilename, kCount, data);

  vector<int> input = data;
  assert(!is_sorted(input.begin(), input.end()));
  Run("MergeSort",
      [&input]() { MergeSort(input.begin(), input.end()); });
  assert(is_sorted(input.begin(), input.end()));

  input = data;
  assert(!is_sorted(input.begin(), input.end()));
  Run("MergeSortBottomUp",
      [&input]() { MergeSortBottomUp(input.begin(), input.end()); });
  assert(is_sorted(input.begin(), input.end()));

  input = data;
  assert(!is_sorted(input.begin(), input.end()));
  Run("HeapSort",
      [&input]() { HeapSort(input.begin(), input.end()); });
  assert(is_sorted(input.begin(), input.end()));

  input = data;
  assert(!is_sorted(input.begin(), input.end()));
  Run("QuickSort",
      [&input]() { QuickSort(input.begin(), input.end()); });
  assert(is_sorted(input.begin(), input.end()));

  input = data;
  assert(!is_sorted(input.begin(), input.end()));
  Run("Sort",
      [&input]() { Sort(input.begin(), input.end()); });
  assert(is_sorted(input.begin(), input.end()));

  input = data;
  assert(!is_sorted(input.begin(), input.end()));
  Run("std::sort",
      [&input]() { std::sort(input.begin(), input.end()); });
  assert(is_sorted(input.begin(), input.end()));

  input = data;
  assert(!is_sorted(input.begin(), input.end()));
  Run("std::stable_sort",
      [&input]() { std::stable_sort(input.begin(), input.end()); });
  assert(is_sorted(input.begin(), input.end()));

  input = data;
  assert(!is_sorted(input.begin(), input.end()));
  Run("CountingSort",
      [&input]() {
	CountingSort(input.begin(), input.end(), 
		     [](int x) { return x; }, 1000);
      });
  assert(is_sorted(input.begin(), input.end()));

  input = data;
  assert(!is_sorted(input.begin(), input.end()));
  Run("RadixSort",
      [&input]() { RadixSort(input.begin(), input.end(), 3); });
  assert(is_sorted(input.begin(), input.end()));

  input = data;
  assert(!is_sorted(input.begin(), input.end()));
  Run("ShellSort",
      [&input]() { ShellSort(input.begin(), input.end()); });
  assert(is_sorted(input.begin(), input.end()));
}

void BenchmarkOnFloat() {
  vector<double> data;
  ReadData(kRandomFloatFilename, kCount, data);

  vector<double> input = data;
  assert(!is_sorted(input.begin(), input.end()));
  Run("MergeSort",
      [&input]() { MergeSort(input.begin(), input.end()); });
  assert(is_sorted(input.begin(), input.end()));

  input = data;
  assert(!is_sorted(input.begin(), input.end()));
  Run("MergeSortBottomUp",
      [&input]() { MergeSortBottomUp(input.begin(), input.end()); });
  assert(is_sorted(input.begin(), input.end()));

  input = data;
  assert(!is_sorted(input.begin(), input.end()));
  Run("HeapSort",
      [&input]() { HeapSort(input.begin(), input.end()); });
  assert(is_sorted(input.begin(), input.end()));

  input = data;
  assert(!is_sorted(input.begin(), input.end()));
  Run("QuickSort",
      [&input]() { QuickSort(input.begin(), input.end()); });
  assert(is_sorted(input.begin(), input.end()));

  input = data;
  assert(!is_sorted(input.begin(), input.end()));
  Run("Sort",
      [&input]() { Sort(input.begin(), input.end()); });
  assert(is_sorted(input.begin(), input.end()));

  input = data;
  assert(!is_sorted(input.begin(), input.end()));
  Run("std::srot",
      [&input]() { sort(input.begin(), input.end()); });
  assert(is_sorted(input.begin(), input.end()));

  input = data;
  assert(!is_sorted(input.begin(), input.end()));
  Run("std::stable_sort",
      [&input]() { std::stable_sort(input.begin(), input.end()); });
  assert(is_sorted(input.begin(), input.end()));

  input = data;
  assert(!is_sorted(input.begin(), input.end()));
  Run("ShellSort",
      [&input]() { ShellSort(input.begin(), input.end()); });
  assert(is_sorted(input.begin(), input.end()));
}
