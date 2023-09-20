#ifndef GRAPHS_ADJACENCY_LIST_CONCEPTS
#define GRAPHS_ADJACENCY_LIST_CONCEPTS

#include <concepts>
#include <type_traits>

#include "AdjacencyList.hxx"
#include "Vertex.hxx"
#include "WeightedVertex.hxx"

namespace Graphs {

template <typename> struct isWeightedVertex : std::false_type {};
template <typename L, typename W>
struct isWeightedVertex<WeightedVertex<L, W>> : std::true_type {};

template <typename T>
concept WeightedVertexConcept =
    requires(T) { requires isWeightedVertex<T>::value; };

template <typename> struct isUnweightedVertex : std::false_type {};
template <typename L> struct isUnweightedVertex<Vertex<L>> : std::true_type {};

template <typename T>
concept UnweightedVertexConcept =
    requires(T) { requires isUnweightedVertex<T>::value; };

template <class> struct isUndirectedGraph : std::false_type {};
template <GraphType type, class V>
struct isUndirectedGraph<AdjacencyList<type, V>> {
   static constexpr bool value = type == GraphType::Undirected;
};

template <class T>
concept UndirectedGraphConcept =
    requires(T) { requires isUndirectedGraph<T>::value; };

} // namespace Graphs

#endif
