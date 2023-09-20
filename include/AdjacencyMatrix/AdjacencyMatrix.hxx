#ifndef GRAPHS_ADJACENCY_MATRIX
#define GRAPHS_ADJACENCY_MATRIX

#include "../Types.hxx"
#include "Matrix.hxx"

namespace Graphs {

// Graph with n unlabeled vertices represented by a matrix
template <GraphType type> class AdjacencyMatrix {
private:
  size_t _size; // number of vertices
  Matrix _vertices;

public:
  // Constructor
  AdjacencyMatrix(size_t size) : _size(size), _vertices(Matrix(size)) {}

  // Destructor
  ~AdjacencyMatrix() {}

  // Adds an unlabel edge
  void AddEdge(const size_t src, const size_t dest) {
    _vertices(src, dest) = 1;
  }

  // Finds an edge
  bool FindEdge(const size_t src, const size_t dest) {
    return _vertices(src, dest) > 0;
  }
};

} // namespace Graphs

#endif
