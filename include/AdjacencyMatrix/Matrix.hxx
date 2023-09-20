#ifndef GRAPHS_ADJACENCY_MATRIX_MATRIX
#define GRAPHS_ADJACENCY_MATRIX_MATRIX

#include <iostream>
#include <vector>

namespace Graphs {

class Matrix {
private:
  size_t _cols;
  std::vector<size_t> _data;

public:
  Matrix(size_t n) : _cols(n) {
    _data.resize(n * n);
    std::fill(_data.begin(), _data.end(), 0);
  }

  const size_t &operator()(size_t i, size_t j) const {
    return _data.at(i * _cols + j);
  }

  size_t &operator()(size_t i, size_t j) { return _data.at(i * _cols + j); }
};

} // namespace Graphs

#endif
