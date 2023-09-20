#ifndef GRAPHS_EDGE_LIST
#define GRAPHS_EDGE_LIST

#include <iostream>
#include <memory>
#include <utility>

namespace Graphs {

// Forward declaration of edge list
template <typename...> class EdgeList {};

// Edge list with unlabeled edges
template <typename V> class EdgeList<V> {
public:
  using VertexPtr = std::shared_ptr<V>;

private:
  std::vector<std::pair<VertexPtr, VertexPtr>> edges;

public:
  EdgeList() {}

  const std::vector<std::pair<VertexPtr, VertexPtr>> &GetEdges() const {
    return edges;
  }

  bool FindEdge(const VertexPtr &u, const VertexPtr &v) {
    for (auto [src, dest] : edges) {
      if (src == u && dest == v) {
        return true;
      }
    }
    return false;
  }

  void AddEdge(const VertexPtr &u, const VertexPtr &v) {
    if (!FindEdge(u, v)) {
      edges.push_back({u, v});
    }
  }

  template <typename VertexTy>
  friend std::ostream &operator<<(std::ostream &os, const EdgeList<VertexTy> &);
};

template <typename V>
std::ostream &operator<<(std::ostream &os, const EdgeList<V> &g) {
  for (auto [u, v] : g.edges) {
    os << "{" << *(u.get()) << " -> " << *(v.get()) << "}\n";
  }
  return os;
}

// Edge list with Labeled edges
template <typename V, typename Label> class EdgeList<V, Label> {
public:
  using VertexPtr = std::shared_ptr<V>;

private:
  std::vector<std::tuple<VertexPtr, VertexPtr, Label>> edges;

public:
  EdgeList() {}

  const std::vector<std::tuple<VertexPtr, VertexPtr, Label>> &GetEdges() const {
    return edges;
  }

  bool FindEdge(const VertexPtr &u, const VertexPtr &v) {
    for (auto [src, dest, w] : edges) {
      if (src == u && dest == v) {
        return true;
      }
    }
    return false;
  }

  void AddEdge(const VertexPtr &u, const VertexPtr &v,
               const Label &label = Label()) {
    if (!FindEdge(u, v)) {
      edges.push_back({u, v, label});
    }
  }

  template <typename VertexTy, typename LabelTy>
  friend std::ostream &operator<<(std::ostream &os,
                                  const EdgeList<VertexTy, LabelTy> &);
};

template <typename V, typename L>
std::ostream &operator<<(std::ostream &os, const EdgeList<V, L> &g) {
  for (auto [u, v, w] : g.edges) {
    os << "{" << *(u.get()) << " -> " << *(v.get()) << " ; " << w << "}\n";
  }
  return os;
}

} // namespace Graphs

#endif
