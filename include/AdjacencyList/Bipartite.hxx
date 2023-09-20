#ifndef GRAPHS_ADJACENCY_LIST_BIPARTITE
#define GRAPHS_ADJACENCY_LIST_BIPARTITE

#include <map>
#include <memory>
#include <optional>
#include <queue>
#include <set>
#include <vector>

namespace Graphs {

// Check if a connected graph is bipartite and returns a decomposition of the
// vertices into two disjoint sets using Bfs
template <class G, class Decomp =
                       std::pair<std::set<std::shared_ptr<typename G::Vertex>>,
                                 std::set<std::shared_ptr<typename G::Vertex>>>>
auto bipartiteGraph(const G &graph) -> std::optional<Decomp> {
   using V = typename G::Vertex;
   auto n = graph.GetVertices()[0];
   std::queue<std::shared_ptr<V>> q;
   q.push(n);
   std::set<std::shared_ptr<V>> visited;
   visited.insert(n);
   std::map<std::shared_ptr<V>, size_t> dist;
   dist[n] = 0;

   while (!q.empty()) {
      auto u = q.front();
      q.pop();
      for (auto &v : u.get()->GetNeighbors()) {
         if (visited.find(v) == visited.end()) {
            // First time we reach v
            dist[v] = dist[u] + 1;
            visited.insert(v);
            q.push(v);
         } else {
            // we reached v before
            // if its in the same depth as u then there is a cycle of odd length
            // and the graph is not bipartite
            if (dist[v] == dist[u]) {
               return std::nullopt;
            }
         }
      }
   }

   Decomp decomp;
   // Decompose the vertices depending on the parity of the length of the
   // shortest path from the source n
   for (auto &[vertex, d] : dist) {
      if (d % 2 == 0) {
         decomp.first.insert(vertex);
      } else {
         decomp.second.insert(vertex);
      }
   }

   return std::optional(decomp);
}

} // namespace Graphs

#endif
