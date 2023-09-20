#ifndef GRPAHS_ADJACENCY_LIST_VERTEX
#define GRPAHS_ADJACENCY_LIST_VERTEX

#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <memory>
#include <vector>
#include <algorithm>

namespace Graphs {

// Labeled vertex
template <typename Label> class Vertex {
public:
  using V = Vertex<Label>;
  using LabelType = Label;

private:
  Label label;
  std::vector<std::shared_ptr<V>> neighbors;

public:
  Vertex(Label &&label = Label()) : label(std::move(label)) {}
  Vertex(const Label &label) : label(label) {}

  const Label &GetLabel() const { return label; }
  void SetLabel(const Label &newLabel) { label = newLabel; }
  void SetLabel(Label &&newLabel) { label = std::move(newLabel); }

  const std::vector<std::shared_ptr<V>> &GetNeighbors() { return neighbors; }
  void AddNeighbor(std::shared_ptr<V> vertex) { neighbors.push_back(vertex); }
  bool FindNeighbor(std::shared_ptr<V> vertex) {
    return std::find(neighbors.begin(), neighbors.end(), vertex) !=
           neighbors.end();
  }

  template <typename L>
  friend std::ostream &operator<<(std::ostream &, const Vertex<L> &);
};
template <typename Label>
std::ostream &operator<<(std::ostream &os, const Vertex<Label> &vertex) {
  os << vertex.label;
  return os;
}

} // namespace Graphs

#endif
