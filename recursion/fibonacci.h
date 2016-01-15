#ifndef RECURSION_FIBONACCI_H_
#define RECURSION_FIBONACCI_H_

// Method 1: use recursion directly.
int FibonacciNumber1(int n);

// Method 2: bottom up.
int FibonacciNumber2(int n);

// Method 3: solve recusion formula.
int FibonacciNumber3(int n);

// Method 4: 2 by 2 matrix raise to the power of n.
int FibonacciNumber4(int n);

// Method 5: compile time. metaprogramming.
template<int n>
struct FibonacciNumber {
  enum {
    value = FibonacciNumber<n-1>::value + FibonacciNumber<n-2>::value
  };
};

template<>
struct FibonacciNumber<0> {
  enum { value = 0 };
};

template<>
struct FibonacciNumber<1> {
  enum { value = 1 };
};

// Method 6: using C++11 constexpr. compile time when param is const.
constexpr int FibonacciNumber6(int n) {
  return n < 2 ? n : FibonacciNumber6(n-1) + FibonacciNumber6(n-2);
}

#endif  // RECURSION_FIBONACCI_H_
