#include <cmath>
#include <vector>
#include "gmock/gmock.h"
#include "strassen.h"

using namespace std;
using namespace testing;

TEST(StrassenTest, NextPowerOfTwo) {
  EXPECT_THAT(next_power_of_two(0), Eq(1));
  EXPECT_THAT(next_power_of_two(1), Eq(1));
  EXPECT_THAT(next_power_of_two(2), Eq(2));
  EXPECT_THAT(next_power_of_two(3), Eq(4));
  EXPECT_THAT(next_power_of_two(13), Eq(16));
  EXPECT_THAT(next_power_of_two(16), Eq(16));
}

TEST(StrassenTest, Operators) {
  Matrix A = {{1,1},{2,2}};
  Matrix B = {{1,2},{3,4}};
  Matrix expected_add = {{2,3},{5,6}};
  Matrix expected_minus = {{0,-1},{-1,-2}};
  EXPECT_THAT(A+B, Eq(expected_add));
  EXPECT_THAT(A-B, Eq(expected_minus));
}

TEST(StrassenTest, CopyMatrix) {
  Matrix A = {{1,1},{2,2}};
  Matrix B(4, vector<int>(4));
  copy_matrix(A, B, A.size(), 0, 0);
  Matrix expected = {{1,1,0,0},
		     {2,2,0,0},
		     {0,0,0,0},
		     {0,0,0,0}};
  EXPECT_THAT(B, Eq(expected));

  Matrix C(4, vector<int>(4));
  copy_matrix(A, C, A.size(), 1, 1);
  expected = {{0,0,0,0},
	      {0,1,1,0},
	      {0,2,2,0},
	      {0,0,0,0}};
  EXPECT_THAT(C, Eq(expected));
}

TEST(StrassenTest, GetBlockMatrix) {
  Matrix A = {{1,2},{3,4}};
  Matrix a,b,c,d;
  get_block_matrix(A, a, b, c, d);
  Matrix expected_a = {{1}};
  Matrix expected_b = {{2}};
  Matrix expected_c = {{3}};
  Matrix expected_d = {{4}};
  EXPECT_THAT(a, Eq(expected_a));
  EXPECT_THAT(b, Eq(expected_b));
  EXPECT_THAT(c, Eq(expected_c));
  EXPECT_THAT(d, Eq(expected_d));
}

TEST(StrassenTest, Strassen) {
  Matrix A = {{1,1},{1,1}};
  Matrix B = {{1,2},{3,4}};
  Matrix expected = {{4,6},{4,6}};
  EXPECT_THAT(strassen(A,B), Eq(expected));
  A = {{1,2,3},{2,3,4},{3,4,5}};
  B = {{1,1,1},{1,1,1},{1,1,1}};
  expected = {{6,6,6},{9,9,9},{12,12,12}};
  EXPECT_THAT(strassen(A,B), Eq(expected));
}
