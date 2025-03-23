#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <cinttypes>
#include <vector>

class Dijkstra {
 public:
  using VertexType = std::uint64_t;
  using DistanceType = std::uint64_t;
  class Edge {
   public:
    Edge(const VertexType destination, const DistanceType distance)
        : destination_(destination), distance_(distance) {}

    VertexType GetDestination() const { return destination_; }
    DistanceType GetDistance() const { return distance_; }

   private:
    VertexType destination_;
    DistanceType distance_;
  };
  using AdjacenciesType = std::vector<Edge>;
  using AdjacencyListType = std::vector<AdjacenciesType>;

  static constexpr DistanceType UNREACHABLE = -1;

  Dijkstra(VertexType starting_vertex,
           std::uint64_t graph_vertex_number,
           const AdjacencyListType& adjacency_list);

  [[nodiscard]] DistanceType GetMinimumDistanceToVertex(
      VertexType vertex) const;
  [[nodiscard]] const std::vector<DistanceType>&
  GetMinimumDistanceToOtherVertexes() const;

 private:
  void BuildShortestDistanceToOtherVertexes(
      VertexType starting_vertex,
      std::uint64_t graph_vertex_number,
      const AdjacencyListType& adjacency_list);

  std::vector<DistanceType> minimum_distance_to_vertexes_;
};

#endif  // DIJKSTRA_H
