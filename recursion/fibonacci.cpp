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
