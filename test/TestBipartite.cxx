#include "../include/AdjacencyList/AdjacencyList.hxx"
#include "../include/AdjacencyList/Bipartite.hxx"
#include "../include/AdjacencyList/Vertex.hxx"

#include <string>

int main() {

   {
      // Bipartite graph
      // From Graphs, Networks and Algorithms (Fourth Edition) by Dieter
      // Jungnickel, Fig. 3.5
      using V = Graphs::Vertex<std::string>;
      using G = Graphs::AdjacencyList<Graphs::GraphType::Directed, V>;

      auto v1 = std::make_shared<V>("s");
      auto v2 = std::make_shared<V>("a");
      auto v3 = std::make_shared<V>("c");
      auto v4 = std::make_shared<V>("b");
      auto v5 = std::make_shared<V>("d");
      auto v6 = std::make_shared<V>("e");
      auto v7 = std::make_shared<V>("f");
      auto v8 = std::make_shared<V>("g");
      auto v9 = std::make_shared<V>("h");

      G graph({v1, v2, v3, v4, v5, v6, v7, v8, v9});

      graph.AddEdge(v1, v2);
      graph.AddEdge(v2, v1);
      graph.AddEdge(v1, v3);
      graph.AddEdge(v3, v1);
      graph.AddEdge(v1, v4);
      graph.AddEdge(v4, v1);
      graph.AddEdge(v2, v5);
      graph.AddEdge(v5, v2);
      graph.AddEdge(v5, v9);
      graph.AddEdge(v9, v5);
      graph.AddEdge(v5, v7);
      graph.AddEdge(v7, v5);
      graph.AddEdge(v4, v6);
      graph.AddEdge(v6, v4);
      graph.AddEdge(v6, v8);
      graph.AddEdge(v8, v6);

      auto m = bipartiteGraph(graph);

      std::cout << "Is the graph G = (V,E) bipartite: " << std::boolalpha
                << m.has_value() << std::endl;
      if (m.has_value()) {
         std::cout << "Decomposition of V into two disjoint sets S and T\n";
         auto s = m.value().first;
         std::cout << " S = {";
         for (auto vertex = s.begin(); vertex != s.end(); vertex++) {
            std::cout << vertex->get()->GetLabel();
            if (std::next(vertex) != s.end()) {
               std::cout << ", ";
            }
         }
         std::cout << "}\n";
         auto t = m.value().second;
         std::cout << " T = {";
         for (auto vertex = t.begin(); vertex != t.end(); vertex++) {
            std::cout << vertex->get()->GetLabel();
            if (std::next(vertex) != t.end()) {
               std::cout << ", ";
            }
         }
         std::cout << "}\n";
      }
   }
}
