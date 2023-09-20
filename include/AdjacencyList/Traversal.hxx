#ifndef GRAPHS_ADJACENCY_LIST_TRAVERSAL
#define GRAPHS_ADJACENCY_LIST_TRAVERSAL

#include "AdjacencyList.hxx"

namespace Graphs {

// Depth first search
template <typename V>
void Dfs(const std::shared_ptr<V> &u,
         std::function<void(const std::shared_ptr<V> &)> f,
         std::unordered_set<std::shared_ptr<V>> &visited) {
  f(u);
  for (auto n : u.get()->GetNeighbors()) {
    if (visited.find(n) == visited.end()) {
      visited.insert(n);
      Dfs(n, f, visited);
    }
  }
}

template <typename V>
void Dfs(const std::shared_ptr<V> &u,
         std::function<void(const std::shared_ptr<V> &)> f) {
  std::unordered_set<std::shared_ptr<V>> visited;
  Dfs(u, f, visited);
}

// Iterative depth first search
template <typename V>
void IterDfs(const std::shared_ptr<V> &u,
             std::function<void(const std::shared_ptr<V> &)> f) {
  std::stack<std::shared_ptr<V>> stack;
  stack.push(u);
  std::unordered_set<std::shared_ptr<V>> visited;
  visited.insert(u);

  while (!stack.empty()) {
    auto v = stack.top();
    stack.pop();
    f(v);
    for (auto n : v.get()->GetNeighbors()) {
      if (visited.find(n) == visited.end()) {
        visited.insert(n);
        stack.push(n);
      }
    }
  }
}

// Breadth first search
template <typename V>
void Bfs(const std::shared_ptr<V> &u,
         std::function<void(const std::shared_ptr<V> &)> f) {
  std::queue<std::shared_ptr<V>> queue;
  queue.push(u);
  std::unordered_set<std::shared_ptr<V>> visited;
  visited.insert(u);

  while (!queue.empty()) {
    auto v = queue.front();
    queue.pop();
    f(v);
    for (auto n : v.get()->GetNeighbors()) {
      if (visited.find(n) == visited.end()) {
        visited.insert(n);
        queue.push(n);
      }
    }
  }
}

} // namespace Graphs

#endif
