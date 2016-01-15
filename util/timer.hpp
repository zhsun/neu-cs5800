#ifndef UTIL_TIMER_H_
#define UTIL_TIMER_H_

#include <chrono>
#include <functional>

template<typename R>
R MeasureTime(std::function<void()> f) {
  using namespace std::chrono;
  auto start = steady_clock::now();
  f();
  auto end = steady_clock::now();
  return duration_cast<R>(end - start);
}

#endif  // UTIL_TIMER_H_
