#include "dijkstra.h"

#include <queue>

Dijkstra::Dijkstra(const VertexType starting_vertex,
                   const std::uint64_t graph_vertex_number,
                   const AdjacencyListType& adjacency_list) {
  BuildShortestDistanceToOtherVertexes(starting_vertex, graph_vertex_number,
                                       adjacency_list);
}

void Dijkstra::BuildShortestDistanceToOtherVertexes(
    const VertexType starting_vertex,
    const std::uint64_t graph_vertex_number,
    const AdjacencyListType& adjacency_list) {
  minimum_distance_to_vertexes_.resize(graph_vertex_number, UNREACHABLE);
  minimum_distance_to_vertexes_[starting_vertex] = 0;

  static constexpr auto edge_greater = [](const Edge& edge1, const Edge& edge2) {
    return edge1.GetDistance() > edge2.GetDistance();
  };

  // The min heap contains virtual edges from starting vertex to other vertexes,
  // sorted by the distances of edges.
  std::priority_queue<Edge, std::vector<Edge>, decltype(edge_greater)>
      min_heap(edge_greater);
  min_heap.push({starting_vertex, 0});

  while (!min_heap.empty()) {
    const Edge min_distance_edge = min_heap.top();
    min_heap.pop();
    const DistanceType current_distance = min_distance_edge.GetDistance();
    const VertexType current_vertex = min_distance_edge.GetDestination();

    if (current_distance > minimum_distance_to_vertexes_[current_vertex]) {
      continue;
    }

    const auto& adjacencies = adjacency_list[current_vertex];
    for (const Edge& edge : adjacencies) {
      const DistanceType edge_distance = edge.GetDistance();
      const VertexType edge_destination = edge.GetDestination();

      const DistanceType new_distance = current_distance + edge_distance;
      if (new_distance < minimum_distance_to_vertexes_[edge_destination]) {
        minimum_distance_to_vertexes_[edge_destination] = new_distance;
        min_heap.push({edge_destination, new_distance});
      }
    }
  }
}

const std::vector<Dijkstra::DistanceType>&
Dijkstra::GetMinimumDistanceToOtherVertexes() const {
  return minimum_distance_to_vertexes_;
}

Dijkstra::DistanceType Dijkstra::GetMinimumDistanceToVertex(
    const VertexType vertex) const {
  return minimum_distance_to_vertexes_[vertex];
}
