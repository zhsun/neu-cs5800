#include <algorithm>
#include <iterator>
#include "strassen.h"

// Forward declare.
int next_power_of_two(int n);
void copy_matrix(const Matrix& f, Matrix& t, int dim, int start_row, int start_col);
void get_block_matrix(const Matrix& A, Matrix& a, Matrix& b, Matrix& c, Matrix& d);
Matrix strassen_rec(const Matrix& A, const Matrix& B);
const Matrix operator+(const Matrix& A, const Matrix& B);
const Matrix operator-(const Matrix& A, const Matrix& B);

// Assume all matrices are square matrices.
Matrix strassen(const Matrix& A, const Matrix& B) {
  // Make the size power of two, so we don't need to deal with odd
  // cases in recursion.
  int n = A.size();
  int m = next_power_of_two(n);
  Matrix largeA(m, std::vector<int>(m)); copy_matrix(A, largeA, n, 0, 0);
  Matrix largeB(m, std::vector<int>(m)); copy_matrix(B, largeB, n, 0, 0);
  Matrix largeC = strassen_rec(largeA, largeB);

  Matrix C(n, std::vector<int>(n));
  copy_matrix(largeC, C, n, 0, 0);
  return C;
}

Matrix strassen_rec(const Matrix& A, const Matrix& B) {
  int n = A.size();
  Matrix C(n, std::vector<int>(n));
  if (n == 1) {
    C[0][0] = A[0][0] * B[0][0];
    return C;
  }
  Matrix a, b, c, d;
  get_block_matrix(A, a, b, c, d);
  Matrix e, g, f, h;
  get_block_matrix(B, e, g, f, h);
  // Calculate p1 to p7.
  Matrix p1 = strassen_rec(a, g-h);
  Matrix p2 = strassen_rec(a+b, h);
  Matrix p3 = strassen_rec(c+d, e);
  Matrix p4 = strassen_rec(d, f-e);
  Matrix p5 = strassen_rec(a+d, e+h);
  Matrix p6 = strassen_rec(b-d, f+h);
  Matrix p7 = strassen_rec(a-c, e+g);
  // Use p1 to p7 to reconstruct the product matrix.
  copy_matrix(p4+p5+p6-p2, C, n/2, 0, 0);
  copy_matrix(p1+p2, C, n/2, 0, n/2);
  copy_matrix(p3+p4, C, n/2, n/2, 0);
  copy_matrix(p1+p5-p3-p7, C, n/2, n/2, n/2);
  return C;
}

// Given a matrix of dimension n, break it into 4 block matrices.
void get_block_matrix(const Matrix& A, Matrix& a, Matrix& b, Matrix& c, Matrix& d) {
  int n = A.size();
  a.resize(n/2); b.resize(n/2); c.resize(n/2); d.resize(n/2);
  for (int r = 0; r < n/2; r++) {
    std::copy(A[r].begin(), A[r].begin()+n/2, std::back_inserter(a[r]));
    std::copy(A[r].begin()+n/2, A[r].end(), std::back_inserter(b[r]));
  }
  for (int r = n/2; r < n; r++) {
    std::copy(A[r].begin(), A[r].begin()+n/2, std::back_inserter(c[r-n/2]));
    std::copy(A[r].begin()+n/2, A[r].end(), std::back_inserter(d[r-n/2]));
  }
}

// Copy over the content (upper left dim*dim part) from "f" to "t"
// (upper left corner specified by "start_row" and "start_col").
void copy_matrix(const Matrix& f, Matrix& t, int dim, int start_row, int start_col) {
  for (int r = 0; r < dim; r++) {
    std::copy(f[r].begin(), f[r].end(), t[r+start_row].begin()+start_col);
  }
}

// + operator for matrix.
const Matrix operator+(const Matrix& A, const Matrix& B) {
  int n = A.size();
  Matrix C(n, std::vector<int>(n));
  for (int r = 0; r < n; r++) {
    for (int c = 0; c < n; c++) {
      C[r][c] = A[r][c] + B[r][c];
    }
  }
  return C;
}

// - operator for matrix.
const Matrix operator-(const Matrix& A, const Matrix& B) {
  int n = A.size();
  Matrix C(n, std::vector<int>(n));
  for (int r = 0; r < n; r++) {
    for (int c = 0; c < n; c++) {
      C[r][c] = A[r][c] - B[r][c];
    }
  }
  return C;
}

int next_power_of_two(int n) {
  if (n == 0) return 1;
  return 1 << static_cast<int>(ceil(log2(n)));
}
