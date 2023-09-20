#ifndef GRAPHS_ADJACENCY_LIST_SHORTEST_PATHS
#define GRAPHS_ADJACENCY_LIST_SHORTEST_PATHS

#include "../Types.hxx"
#include "Concepts.hxx"

#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <stdexcept>
#include <unordered_set>

namespace Graphs {

enum class ShortestPathAlgorithm { Djikstra, Bfs, Unknown };

// Find the shortest paths from a single source to all the reachable vertices in
// a unweighted graph
template <GraphType type, UnweightedVertexConcept V,
          typename Dist = std::map<std::shared_ptr<V>, size_t>,
          typename Vis = std::unordered_set<std::shared_ptr<V>>>
auto SingleSourceShortestPaths(
    std::shared_ptr<V> source,
    ShortestPathAlgorithm alg = ShortestPathAlgorithm::Bfs) -> Dist {
   if (alg == ShortestPathAlgorithm::Bfs) {
      Vis visited;
      Dist dist;
      std::queue<std::shared_ptr<V>> q;
      q.push(source);
      visited.insert(source);

      // Set the distance to source to zero
      dist[source] = 0;

      while (!q.empty()) {
         auto u = q.front();
         q.pop();
         for (auto v : u.get()->GetNeighbors()) {
            if (visited.find(v) == visited.end()) {
               visited.insert(v);
               dist[v] = dist[u] + 1;
               q.push(v);
            }
         }
      }
      return dist;
   } else {
      throw std::runtime_error("Algorithm not implemented.");
   }
}

// Find the shortest paths from a single source to all the reachable vertices in
// a weighted graph
template <GraphType type, WeightedVertexConcept V,
          typename Dist = std::map<std::shared_ptr<V>, typename V::W>,
          typename Vis = std::unordered_set<std::shared_ptr<V>>>
auto SingleSourceShortestPaths(
    std::shared_ptr<V> source,
    ShortestPathAlgorithm alg = ShortestPathAlgorithm::Djikstra) -> Dist {
   if (alg == ShortestPathAlgorithm::Djikstra) {
      using W = typename V::W;
      Dist dist;
      Vis vis;

      // Distance from the source to itself is zero
      dist[source] = W(0.);
      // Mark source as visited
      vis.insert(source);

      // Compare two paths
      auto Comp = [](std::pair<std::shared_ptr<V>, W> u,
                     std::pair<std::shared_ptr<V>, W> v) {
         return u.second < v.second;
      };

      // Prority queue of vertices and their distances
      std::priority_queue<std::pair<std::shared_ptr<V>, W>,
                          std::vector<std::pair<std::shared_ptr<V>, W>>,
                          decltype(Comp)>
          q;

      q.push({source, dist[source]});

      while (!q.empty()) {
         // Processing node u
         auto [u, distu] = q.top();
         q.pop();

         // Process all the outgoing edges from u
         for (auto [v, w] : u.get()->GetNeighbors()) {
            if (dist.find(v) == dist.end()) {
               // First time we reach v
               dist[v] = distu + w;
            } else {
               // we reached v before, check if this path is shorter
               dist[v] = std::min(dist[v], distu + w);
            }
            // If v is not visited, add it to the queue with priority dist[v]
            if (vis.find(v) == vis.end()) {
               q.push({v, dist[v]});
            }
         }
      }
      return dist;
   } else {
      throw std::runtime_error("Algorithm not implemented.");
   }
}

} // namespace Graphs

#endif
