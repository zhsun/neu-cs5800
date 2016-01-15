#include "gmock/gmock.h"
#include "recursion/fibonacci.h"

using namespace testing;

TEST(FibonacciNumberTest, Methods1) {
  EXPECT_THAT(FibonacciNumber1(0), Eq(0));
  EXPECT_THAT(FibonacciNumber1(1), Eq(1));
  EXPECT_THAT(FibonacciNumber1(2), Eq(1));
  EXPECT_THAT(FibonacciNumber1(3), Eq(2));
  EXPECT_THAT(FibonacciNumber1(4), Eq(3));
  EXPECT_THAT(FibonacciNumber1(5), Eq(5));
  EXPECT_THAT(FibonacciNumber1(6), Eq(8));
  EXPECT_THAT(FibonacciNumber1(7), Eq(13));
  EXPECT_THAT(FibonacciNumber1(8), Eq(21));
  EXPECT_THAT(FibonacciNumber1(9), Eq(34));
  EXPECT_THAT(FibonacciNumber1(10), Eq(55));
}

TEST(FibonacciNumberTest, Methods2) {
  EXPECT_THAT(FibonacciNumber2(0), Eq(0));
  EXPECT_THAT(FibonacciNumber2(1), Eq(1));
  EXPECT_THAT(FibonacciNumber2(2), Eq(1));
  EXPECT_THAT(FibonacciNumber2(3), Eq(2));
  EXPECT_THAT(FibonacciNumber2(4), Eq(3));
  EXPECT_THAT(FibonacciNumber2(5), Eq(5));
  EXPECT_THAT(FibonacciNumber2(6), Eq(8));
  EXPECT_THAT(FibonacciNumber2(7), Eq(13));
  EXPECT_THAT(FibonacciNumber2(8), Eq(21));
  EXPECT_THAT(FibonacciNumber2(9), Eq(34));
  EXPECT_THAT(FibonacciNumber2(10), Eq(55));
}
