#include "include/AdjacencyList/AdjacencyList.hxx"
#include "include/AdjacencyList/Traversal.hxx"
#include "include/AdjacencyMatrix/AdjacencyMatrix.hxx"
#include "include/EdgeList/EdgeList.hxx"

#include <iostream>

int main() {
  // Vertex type
  using Vertex = Graphs::Vertex<std::string>;
  // Vertices
  auto A = std::make_shared<Vertex>("A");
  auto B = std::make_shared<Vertex>("B");
  auto C = std::make_shared<Vertex>("C");
  auto D = std::make_shared<Vertex>("D");
  auto E = std::make_shared<Vertex>("E");
  auto F = std::make_shared<Vertex>("F");
  auto G = std::make_shared<Vertex>("G");
  auto H = std::make_shared<Vertex>("H");

  {
    std::cout << "AdjacencyList" << std::endl;
    using Graph = Graphs::AdjacencyList<Graphs::GraphType::Directed, Vertex>;
    Graph g;

    g.AddVertex(A);
    g.AddVertex(B);
    g.AddVertex(C);
    g.AddVertex(D);
    g.AddVertex(E);
    g.AddVertex(F);
    g.AddVertex(G);
    g.AddVertex(H);

    g.AddEdge(A, B);
    g.AddEdge(A, C);
    g.AddEdge(B, D);
    g.AddEdge(B, E);
    g.AddEdge(E, H);
    g.AddEdge(C, F);
    g.AddEdge(C, G);

    auto print = [](const std::shared_ptr<Vertex> &v) {
      std::cout << "[" << v.get()->GetLabel() << "] ";
    };
    std::cout << "BFS\n";
    Graphs::Bfs<Vertex>(A, print);
    std::cout << std::endl;

    std::cout << "Recursive DFS\n";
    Graphs::Dfs<Vertex>(A, print);
    std::cout << std::endl;

    std::cout << "Iterative DFS\n";
    Graphs::IterDfs<Vertex>(A, print);
    std::cout << std::endl;
  }

  {
    using Edge = Graphs::EdgeList<Graphs::Vertex<std::string>, size_t>;
    Edge e;

    e.AddEdge(A, B, 3);
    e.AddEdge(A, C, 5);
    e.AddEdge(B, D, 11);
    e.AddEdge(B, E, 2);
    e.AddEdge(E, H, 4);
    e.AddEdge(C, F, 5);
    e.AddEdge(C, G, 19);

    std::cout << std::endl << "Edge list\n";
    std::cout << e << std::endl;
  }

  {
    using Graph = Graphs::AdjacencyMatrix<Graphs::GraphType::Undirected>;

    size_t n = 5;
    Graph g(n);
    for (size_t i = 0; i < n; i++) {
      for (size_t j = i + 1; j < n; j++) {
        g.AddEdge(i, j);
        g.AddEdge(j, i);
      }
    }

    std::cout << "AdjacencyMatrix" << std::endl;
    for (size_t i = 0; i < n; i++) {
      for (size_t j = 0; j < n; j++) {
        std::cout << (g.FindEdge(i, j) ? "x" : " ") << " ";
      }
      std::cout << std::endl;
    }
  }
}
