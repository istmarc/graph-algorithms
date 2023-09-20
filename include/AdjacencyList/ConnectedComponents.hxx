#ifndef GRAPHS_ADJACENCY_LIST_CONNECTED_COMPONENTS
#define GRAPHS_ADJACENCY_LIST_CONNECTED_COMPONENTS

#include "Concepts.hxx"
#include "Traversal.hxx"
#include "Vertex.hxx"
#include <functional>
#include <memory>
#include <stack>
#include <stdexcept>

namespace Graphs {

enum class ConnectedComponentsAlgorithm { Dfs, Bfs, Unknown };

template <
    UndirectedGraphConcept G,
    class Comp = std::vector<std::set<std::shared_ptr<typename G::Vertex>>>,
    class Vis = std::set<std::shared_ptr<typename G::Vertex>>>
auto connectedComponents(G graph, ConnectedComponentsAlgorithm alg =
                                      ConnectedComponentsAlgorithm::Dfs)
    -> Comp {
   if (alg == ConnectedComponentsAlgorithm::Dfs ||
       alg == ConnectedComponentsAlgorithm::Bfs) {
      Comp allComp;
      Vis vis;
      for (auto &u : graph.GetVertices()) {
         if (vis.find(u) == vis.end()) {
            // Create a new component
            typename Comp::value_type comp;
            using vertex_type = typename G::Vertex;
            std::function<void(const std::shared_ptr<vertex_type> &)> f =
                [&vis, &comp](const std::shared_ptr<vertex_type> &u) {
                   vis.insert(u);
                   comp.insert(u);
                };
            // Run Dfs or Bfs from u
            // u and all the reachable vertices are connected
            if (alg == ConnectedComponentsAlgorithm::Dfs) {
               Dfs<vertex_type>(u, f);
            } else if (alg == ConnectedComponentsAlgorithm::Bfs) {
               Bfs<vertex_type>(u, f);
            }
            allComp.push_back(comp);
         }
      }
      return allComp;
   } else {
      throw std::runtime_error(
          "Connected components algorithm not implemented.");
   }
}

} // namespace Graphs

#endif
