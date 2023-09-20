#include "../include/AdjacencyList/AdjacencyList.hxx"
#include "../include/AdjacencyList/ConnectedComponents.hxx"
#include "../include/AdjacencyList/Vertex.hxx"

#include <string>

using V = Graphs::Vertex<std::string>;
using G = Graphs::AdjacencyList<Graphs::GraphType::Undirected, V>;
using Graphs::ConnectedComponentsAlgorithm;

void TestConnectedComponents(const G &graph, ConnectedComponentsAlgorithm alg) {
   auto m = Graphs::connectedComponents(graph, alg);

   if (alg == ConnectedComponentsAlgorithm::Dfs) {
      std::cout << "Dfs";
   } else if (alg == ConnectedComponentsAlgorithm::Bfs) {
      std::cout << "Bfs";
   }
   std::cout << " based connected components algorithm\n";

   std::cout << "Is the graph G = (V,E) connected: " << std::boolalpha
             << (m.size() == 1) << std::endl;
   if (m.size() > 1) {
      std::cout << "Number of connected components: " << m.size() << std::endl;
   }
   for (size_t n = 0; n < m.size(); n++) {
      auto comp = m[n];
      std::cout << "Component " << n << ": {";
      for (auto vertex = comp.begin(); vertex != comp.end(); vertex++) {
         std::cout << vertex->get()->GetLabel();
         if (std::next(vertex) != comp.end()) {
            std::cout << ", ";
         }
      }
      std::cout << "}\n";
   }
   std::cout << std::endl;
}
int main() {

   auto v1 = std::make_shared<V>("a");
   auto v2 = std::make_shared<V>("b");
   auto v3 = std::make_shared<V>("c");
   auto v4 = std::make_shared<V>("d");
   auto v5 = std::make_shared<V>("e");
   auto v6 = std::make_shared<V>("f");
   auto v7 = std::make_shared<V>("g");
   auto v8 = std::make_shared<V>("h");
   auto v9 = std::make_shared<V>("i");

   G graph({v1, v2, v3, v4, v5, v6, v7, v8, v9});

   // a, b, c, d
   graph.AddEdge(v2, v1);
   graph.AddEdge(v1, v2);
   graph.AddEdge(v2, v3);
   graph.AddEdge(v3, v2);
   graph.AddEdge(v2, v4);
   graph.AddEdge(v4, v2);
   // e,g
   graph.AddEdge(v5, v7);
   graph.AddEdge(v7, v5);
   // f, h i
   graph.AddEdge(v6, v8);
   graph.AddEdge(v8, v6);
   graph.AddEdge(v6, v9);
   graph.AddEdge(v9, v6);

   TestConnectedComponents(graph, ConnectedComponentsAlgorithm::Dfs);
   TestConnectedComponents(graph, ConnectedComponentsAlgorithm::Bfs);
}
