#include "../include/AdjacencyList/AdjacencyList.hxx"
#include "../include/AdjacencyList/ShortestPaths.hxx"
#include "../include/AdjacencyList/Vertex.hxx"
#include "../include/AdjacencyList/WeightedList.hxx"
#include "../include/AdjacencyList/WeightedVertex.hxx"

#include <string>

int main() {

   {
      // Find all the shortest paths from a single source
      // From Graphs, Networks and Algorithms (Fourth Edition) by Dieter
      // Jungnickel, P. 85 / Example 3.7.5 / Fig. 3.8
      using V = Graphs::WeightedVertex<std::string, size_t>;
      using G = Graphs::WeightedList<Graphs::GraphType::Directed, V>;

      G graph;

      auto v1 = std::make_shared<V>("v1");
      auto v2 = std::make_shared<V>("v2");
      auto v3 = std::make_shared<V>("v3");
      auto v4 = std::make_shared<V>("v4");
      auto v5 = std::make_shared<V>("v5");
      auto v6 = std::make_shared<V>("v6");
      auto v7 = std::make_shared<V>("v7");
      auto v8 = std::make_shared<V>("v8");

      graph.AddEdge(v1, v3, 2);
      graph.AddEdge(v1, v2, 28);
      graph.AddEdge(v1, v5, 1);
      graph.AddEdge(v2, v4, 9);
      graph.AddEdge(v2, v6, 10);
      graph.AddEdge(v3, v6, 24);
      graph.AddEdge(v3, v8, 27);
      graph.AddEdge(v4, v8, 28);
      graph.AddEdge(v4, v7, 8);
      graph.AddEdge(v4, v8, 7);
      graph.AddEdge(v5, v2, 8);
      graph.AddEdge(v5, v6, 26);
      graph.AddEdge(v6, v7, 8);
      graph.AddEdge(v6, v8, 1);
      graph.AddEdge(v7, v8, 7);

      auto dist =
          Graphs::SingleSourceShortestPaths<Graphs::GraphType::Directed, V>(
              v1, Graphs::ShortestPathAlgorithm::Djikstra);
      std::cout << "Djikstra - Shortest path from v1 to" << std::endl;
      for (auto &[vertex, d] : dist) {
         std::cout << vertex.get()->GetLabel() << ": " << d << std::endl;
      }
   }

   {
      // Find all the shortest paths from a single source
      // From Graphs, Networks and Algorithms (Fourth Edition) by Dieter
      // Jungnickel, P. 85 / Example 3.7.5 / Fig. 3.8 but with an undirected
      // unweigthed graph
      using V = Graphs::Vertex<std::string>;
      using G = Graphs::AdjacencyList<Graphs::GraphType::Undirected, V>;
      G graph;

      auto v1 = std::make_shared<V>("v1");
      auto v2 = std::make_shared<V>("v2");
      auto v3 = std::make_shared<V>("v3");
      auto v4 = std::make_shared<V>("v4");
      auto v5 = std::make_shared<V>("v5");
      auto v6 = std::make_shared<V>("v6");
      auto v7 = std::make_shared<V>("v7");
      auto v8 = std::make_shared<V>("v8");

      graph.AddEdge(v1, v3);
      graph.AddEdge(v3, v1);
      graph.AddEdge(v1, v2);
      graph.AddEdge(v2, v1);
      graph.AddEdge(v1, v5);
      graph.AddEdge(v5, v1);
      graph.AddEdge(v2, v4);
      graph.AddEdge(v4, v2);
      graph.AddEdge(v2, v6);
      graph.AddEdge(v6, v2);
      graph.AddEdge(v3, v6);
      graph.AddEdge(v6, v3);
      graph.AddEdge(v3, v8);
      graph.AddEdge(v8, v3);
      graph.AddEdge(v4, v8);
      graph.AddEdge(v8, v4);
      graph.AddEdge(v4, v7);
      graph.AddEdge(v7, v4);
      graph.AddEdge(v4, v8);
      graph.AddEdge(v8, v4);
      graph.AddEdge(v5, v2);
      graph.AddEdge(v2, v5);
      graph.AddEdge(v5, v6);
      graph.AddEdge(v6, v5);
      graph.AddEdge(v6, v7);
      graph.AddEdge(v7, v6);
      graph.AddEdge(v6, v8);
      graph.AddEdge(v8, v6);
      graph.AddEdge(v7, v8);
      graph.AddEdge(v8, v7);

      auto dist =
          Graphs::SingleSourceShortestPaths<Graphs::GraphType::Undirected, V>(
              v1, Graphs::ShortestPathAlgorithm::Bfs);
      std::cout << "Bfs - Shortest path from v1 to" << std::endl;
      for (auto &[vertex, d] : dist) {
         std::cout << vertex.get()->GetLabel() << ": " << d << std::endl;
      }
   }
}
