#include "gmock/gmock.h"
#include "matrix_multiplication.h"

using namespace std;
using namespace testing;

TEST(MatrixMultiplicationTest, SingleMatrix) {
  EXPECT_THAT(MatrixMultiplication({3,4}), Eq(0));
}

TEST(MatrixMultiplicationTest, TwoMatrix) {
  EXPECT_THAT(MatrixMultiplication({3,4,5}), Eq(3 * 4 * 5));
}

TEST(MatrixMultiplicationTest, GeneralCase) {
  // A * ((B * C) * D) gives 120,200
  // (A * (B * C)) * D gives 60,200
  // (A * B) * (C * D) gives 7,000
  EXPECT_THAT(MatrixMultiplication({50,20,1,10,100}), Eq(7000));
}
