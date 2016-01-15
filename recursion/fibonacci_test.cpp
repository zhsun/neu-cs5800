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

TEST(FibonacciNumberTest, Methods3) {
  EXPECT_THAT(FibonacciNumber3(0), Eq(0));
  EXPECT_THAT(FibonacciNumber3(1), Eq(1));
  EXPECT_THAT(FibonacciNumber3(2), Eq(1));
  EXPECT_THAT(FibonacciNumber3(3), Eq(2));
  EXPECT_THAT(FibonacciNumber3(4), Eq(3));
  EXPECT_THAT(FibonacciNumber3(5), Eq(5));
  EXPECT_THAT(FibonacciNumber3(6), Eq(8));
  EXPECT_THAT(FibonacciNumber3(7), Eq(13));
  EXPECT_THAT(FibonacciNumber3(8), Eq(21));
  EXPECT_THAT(FibonacciNumber3(9), Eq(34));
  EXPECT_THAT(FibonacciNumber3(10), Eq(55));
}

TEST(FibonacciNumberTest, Methods4) {
  EXPECT_THAT(FibonacciNumber4(0), Eq(0));
  EXPECT_THAT(FibonacciNumber4(1), Eq(1));
  EXPECT_THAT(FibonacciNumber4(2), Eq(1));
  EXPECT_THAT(FibonacciNumber4(3), Eq(2));
  EXPECT_THAT(FibonacciNumber4(4), Eq(3));
  EXPECT_THAT(FibonacciNumber4(5), Eq(5));
  EXPECT_THAT(FibonacciNumber4(6), Eq(8));
  EXPECT_THAT(FibonacciNumber4(7), Eq(13));
  EXPECT_THAT(FibonacciNumber4(8), Eq(21));
  EXPECT_THAT(FibonacciNumber4(9), Eq(34));
  EXPECT_THAT(FibonacciNumber4(10), Eq(55));
}

TEST(FibonacciNumberTest, Methods5) {
  EXPECT_THAT(FibonacciNumber<0>::value, Eq(0));
  EXPECT_THAT(FibonacciNumber<1>::value, Eq(1));
  EXPECT_THAT(FibonacciNumber<2>::value, Eq(1));
  EXPECT_THAT(FibonacciNumber<3>::value, Eq(2));
  EXPECT_THAT(FibonacciNumber<4>::value, Eq(3));
  EXPECT_THAT(FibonacciNumber<5>::value, Eq(5));
  EXPECT_THAT(FibonacciNumber<6>::value, Eq(8));
  EXPECT_THAT(FibonacciNumber<7>::value, Eq(13));
  EXPECT_THAT(FibonacciNumber<8>::value, Eq(21));
  EXPECT_THAT(FibonacciNumber<9>::value, Eq(34));
  EXPECT_THAT(FibonacciNumber<10>::value, Eq(55));
}

TEST(FibonacciNumberTest, Methods6) {
  EXPECT_THAT(FibonacciNumber6(0), Eq(0));
  EXPECT_THAT(FibonacciNumber6(1), Eq(1));
  EXPECT_THAT(FibonacciNumber6(2), Eq(1));
  EXPECT_THAT(FibonacciNumber6(3), Eq(2));
  EXPECT_THAT(FibonacciNumber6(4), Eq(3));
  EXPECT_THAT(FibonacciNumber6(5), Eq(5));
  EXPECT_THAT(FibonacciNumber6(6), Eq(8));
  EXPECT_THAT(FibonacciNumber6(7), Eq(13));
  EXPECT_THAT(FibonacciNumber6(8), Eq(21));
  EXPECT_THAT(FibonacciNumber6(9), Eq(34));
  EXPECT_THAT(FibonacciNumber6(10), Eq(55));
}
