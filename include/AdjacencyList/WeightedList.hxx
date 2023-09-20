#ifndef GRAPHS_ADJACENCY_WEIGHTED_LIST
#define GRAPHS_ADJACENCY_WEIGHTED_LIST

#include <unordered_set>

#include "Vertex.hxx"

#include "../Types.hxx"

namespace Graphs {

// Graph G = (V, E)
// type : Type of the graph (directed / undirected)
// V : Type of vertex
template <GraphType type, class V> class WeightedList {
 public:
   using W = typename V::W;

 private:
   std::unordered_set<std::shared_ptr<V>> vertices;

 public:
   // Constructor
   WeightedList() {}

   // Returns the vertices
   const std::unordered_set<std::shared_ptr<V>> &GetVertices() const {
      return vertices;
   }

   // Empty graph
   bool Empty() const { return vertices.empty(); }

   // Adds a vertex
   void AddVertex(std::shared_ptr<V> vertex) {
      vertices.insert(vertex);
   }

   // Finds a vertex
   bool FindVertex(const std::shared_ptr<V> &vertex) const {
      return vertices.find(vertex) != vertices.end();
   }

   // Adds an edge
   void AddEdge(std::shared_ptr<V> src, std::shared_ptr<V> dest, W weight) {
      src.get()->AddNeighbor(dest, weight);
   }
};

} // namespace Graphs

#endif
