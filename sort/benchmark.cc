#include <algorithm>
#include <cassert>
#include <chrono>
#include <cstddef>
#include <fstream>
#include <functional>
#include <iostream>
#include <vector>

#include "sort/heapsort/heap_sort.h"
#include "sort/quicksort/quick_sort.h"

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
  vector<int> input;
  ReadData(kRandomIntFilename, kCount, input);
  vector<int> sort_input = input;
  cout << "Quicksort on 1M integers." << endl;
  MeasureTime(bind(Quicksort, sort_input));

  cout << "Heapsort on 1M integers." << endl;
  sort_input = input;
  MeasureTime(bind(Heapsort, sort_input));

  cout << "std::sort on 1M integers." << endl;
  sort_input = input;
  MeasureTime(bind(std::sort<vector<int>::iterator>,
		   sort_input.begin(),
		   sort_input.end()));

  cout << "std::stable_sort on 1M integers." << endl;
  sort_input = input;
  MeasureTime(bind(std::stable_sort<vector<int>::iterator>,
		   sort_input.begin(),
		   sort_input.end()));
}

int main() {
  BenchmarkOnInts();
  return 0;
}
