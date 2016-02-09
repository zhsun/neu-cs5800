#ifndef DP_MATRIX_MULTIPLICATION_H_
#define DP_MATRIX_MULTIPLICATION_H_

#include <cstddef>
#include <vector>

// Returns the minimum number of scale multiplications needed.
size_t MatrixMultiplication(const std::vector<size_t>& dims);

#endif  // DP_MATRIX_MULTIPLICATION_H_
