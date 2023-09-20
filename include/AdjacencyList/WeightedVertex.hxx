#ifndef GRAPHS_ADJACENCY_LIST_WEIGHTED_VERTEX
#define GRAPHS_ADJACENCY_LIST_WEIGHTED_VERTEX

#include <vector>
#include <memory>
#include <unordered_set>
#include <utility>

namespace Graphs {

// The vertex itself is not weighted but the edges to its neighbors are
template <class Label, class Weight> class WeightedVertex {
 public:
   using V = WeightedVertex<Label, Weight>;
   using L = Label;
   using W = Weight;
   using E = std::tuple<std::shared_ptr<V>, Weight>;

 private:
   Label label = Label();
   std::vector<E> neighbors;

 public:
   WeightedVertex() {}
   WeightedVertex(const Label &l) : label(l) {}
   WeightedVertex(Label &&l) : label(std::move(l)) {}

   const Label &GetLabel() const { return label; }

   void SetLabel(const Label &newLabel) { label = newLabel; }
   void SetLabel(Label &&newLabel) { label = std::move(newLabel); }

   const std::vector<E> &GetNeighbors() { return neighbors; }

   void AddNeighbor(std::shared_ptr<V> vertex, Weight w) {
      neighbors.push_back(E(vertex, w));
   }

   template <class L, class W>
   friend std::ostream &operator<<(std::ostream &,
                                   const WeightedVertex<L, W> &);
};

template <class Label, class Weight>
std::ostream &operator<<(std::ostream &os,
                         const WeightedVertex<Label, Weight> &vertex) {
   os << vertex.label;
   return os;
}

} // namespace Graphs

#endif
