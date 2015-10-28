#include <vector>

using Matrix = std::vector<std::vector<int>>;
const Matrix operator+(const Matrix& A, const Matrix& B);
const Matrix operator-(const Matrix& A, const Matrix& B);

Matrix strassen(const Matrix& A, const Matrix& B);

int next_power_of_two(int n);
void copy_matrix(const Matrix& f, Matrix& t, int dim, int start_row, int start_col);
void get_block_matrix(const Matrix& A, Matrix& a, Matrix& b, Matrix& c, Matrix& d);
