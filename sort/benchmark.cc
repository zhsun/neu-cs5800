#include <algorithm>
#include <cassert>
#include <chrono>
#include <cstddef>
#include <fstream>
#include <functional>
#include <iostream>
#include <vector>

#include "sort/heap_sort.hpp"
#include "sort/merge_sort.hpp"
#include "sort/quick_sort.hpp"

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

void MeasureTime(std::function<void()> f) {
  using namespace std::chrono;
  auto start = high_resolution_clock::now();
  f();
  auto end = high_resolution_clock::now();
  cout << "Time used: " 
       << duration_cast<milliseconds>(end - start).count()
       << " milliseconds. " << endl;
}

void BenchmarkOnInts() {
  vector<int> data;
  ReadData(kRandomIntFilename, kCount, data);

  cout << "QuickSort on 1M integers." << endl;
  vector<int> input = data;
  MeasureTime([&input]() { QuickSort(input.begin(), input.end()); });

  cout << "HeapSort on 1M integers." << endl;
  input = data;
  MeasureTime([&input]() { HeapSort(input.begin(), input.end()); });

  cout << "MergeSort on 1M integers." << endl;
  input = data;
  MeasureTime([&input]() { MergeSort(input.begin(), input.end()); });

  cout << "std::sort on 1M integers." << endl;
  input = data;
  MeasureTime([&input]() { sort(input.begin(), input.end()); });

  cout << "std::stable_sort on 1M integers." << endl;
  input = data;
  MeasureTime([&input]() { std::stable_sort(input.begin(), input.end()); });
}

int main() {
  BenchmarkOnInts();
  return 0;
}
