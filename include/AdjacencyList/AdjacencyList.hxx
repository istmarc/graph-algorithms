#ifndef GRAPHS_ADJACENCY_LIST
#define GRAPHS_ADJACENCY_LIST

#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <stdexcept>
#include <string>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <memory>

#include "Vertex.hxx"

#include "../Types.hxx"

namespace Graphs {

// Graph G = (V, E)
// type : Type of the graph (directed / undirected)
// V : Type of vertex
template <GraphType type, typename V> class AdjacencyList {
public:
   using Vertex = V;

private:
  std::vector<std::shared_ptr<V>> vertices;

public:
  // Constructor
  AdjacencyList() {}

   AdjacencyList(const std::vector<std::shared_ptr<V>>& v): vertices(v) {}

  // Returns the vertices
  const std::vector<std::shared_ptr<V>> &GetVertices() const {
    return vertices;
  }

  // Empty graph
  bool Empty() const { return vertices.empty(); }

  // Adds a vertex
  void AddVertex(std::shared_ptr<V> vertex) {
      vertices.push_back(vertex);
  }

   void AddVertices(const std::vector<std::shared_ptr<V>>& v) {
      for (auto& vertex: v) {
         vertices.push_back(vertex);
      }
   }

  // Finds a vertex
  bool FindVertex(const std::shared_ptr<V> &vertex) const {
    return std::find(vertices.begin(), vertices.end(), vertex) !=
           vertices.end();
  }

  // Adds an edge
  void AddEdge(std::shared_ptr<V> src, std::shared_ptr<V> dest) {
    if (!FindEdge(src, dest))
      src.get()->AddNeighbor(dest);
  }

  // Finds an edge
  bool FindEdge(const std::shared_ptr<V> &src, const std::shared_ptr<V> &dest) {
    return src.get()->FindNeighbor(dest);
  }
};
} // namespace Graphs

#endif
