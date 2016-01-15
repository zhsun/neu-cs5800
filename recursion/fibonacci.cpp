#include <cassert>
#include <vector>
#include "recursion/fibonacci.h"

int FibonacciNumber1(int n) {
  if (n == 0 || n == 1) return n;
  return FibonacciNumber1(n-1) + FibonacciNumber1(n-2);
}

int FibonacciNumber2(int n) {
  if (n == 0 || n == 1) return n;
  int two_ahead = 0;
  int one_ahead = 1;
  for (int i = 2; i <= n; ++i) {
    int cur = two_ahead + one_ahead;
    two_ahead = one_ahead;
    one_ahead = cur;
  }
  return one_ahead;
}

template<typename T>
T power(const T& x, int n) {
  assert(n > 0);
  if (n == 1) return x;
  if (n & 1) {  // Odd.
    return x * power(x, n-1);
  }
  // Even.
  const T& val = power(x, n >> 1);
  return val * val;
}

const double kRoot5 = 2.2360679775;
const double kGoldenRatio = 1.61803399;

int RoundToCloseInt(double x) {
  return static_cast<int>(x + 0.5);
}

int FibonacciNumber3(int n) {
  if (n == 0 || n == 1) return n;
  return RoundToCloseInt(power(kGoldenRatio, n) / kRoot5);
}

class A {
 public:
  A() : data_({1, 1, 1, 0}) { }
  int operator[](int i) const {
    assert(i >= 0 && i < kSize);
    return data_[i];
  }
  int& operator[](int i) {
    assert(i >= 0 && i < kSize);
    return data_[i];
  }
 private:
  std::vector<int> data_;
  static const int kSize = 4;
};

A operator*(const A& x, const A& y) {
  A r;
  r[0] = x[0] * y[0] + x[1] * y[2];
  r[1] = x[0] * y[1] + x[1] * y[3];
  r[2] = x[2] * y[0] + x[3] * y[2];
  r[3] = x[2] * y[1] + x[3] * y[3];
  return r;
}

int FibonacciNumber4(int n) {
  if (n == 0 || n == 1) return n;
  const A& r = power(A(), n-1);
  return r[0];
}
