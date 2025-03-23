#include <gtest/gtest.h>
#include "dijkstra.h"

TEST(DijkstraTest, BasicFunctionality) {
  Dijkstra::AdjacencyListType adjacency_list(5);
  adjacency_list[0].emplace_back(1, 10);
  adjacency_list[0].emplace_back(2, 3);
  adjacency_list[1].emplace_back(2, 1);
  adjacency_list[1].emplace_back(3, 2);
  adjacency_list[2].emplace_back(1, 4);
  adjacency_list[2].emplace_back(3, 8);
  adjacency_list[2].emplace_back(4, 2);
  adjacency_list[3].emplace_back(4, 7);
  adjacency_list[4].emplace_back(3, 9);

  Dijkstra dijkstra(0, 5, adjacency_list);

  EXPECT_EQ(dijkstra.GetMinimumDistanceToVertex(0), 0);
  EXPECT_EQ(dijkstra.GetMinimumDistanceToVertex(1), 7);
  EXPECT_EQ(dijkstra.GetMinimumDistanceToVertex(2), 3);
  EXPECT_EQ(dijkstra.GetMinimumDistanceToVertex(3), 9);
  EXPECT_EQ(dijkstra.GetMinimumDistanceToVertex(4), 5);
}

TEST(DijkstraTest, SingleVertex) {
  Dijkstra::AdjacencyListType adjacency_list(1);

  Dijkstra dijkstra(0, 1, adjacency_list);

  EXPECT_EQ(dijkstra.GetMinimumDistanceToVertex(0), 0);
}

TEST(DijkstraTest, DisconnectedGraph) {
  Dijkstra::AdjacencyListType adjacency_list(4);
  adjacency_list[0].emplace_back(1, 1);
  adjacency_list[1].emplace_back(2, 2);

  Dijkstra dijkstra(0, 4, adjacency_list);

  EXPECT_EQ(dijkstra.GetMinimumDistanceToVertex(0), 0);
  EXPECT_EQ(dijkstra.GetMinimumDistanceToVertex(1), 1);
  EXPECT_EQ(dijkstra.GetMinimumDistanceToVertex(2), 3);
  EXPECT_EQ(dijkstra.GetMinimumDistanceToVertex(3), Dijkstra::UNREACHABLE);
}

TEST(DijkstraTest, LargeGraph) {
  const std::uint64_t graph_vertex_number = 1000;
  Dijkstra::AdjacencyListType adjacency_list(graph_vertex_number);

  for (std::uint64_t i = 0; i < graph_vertex_number - 1; ++i) {
    adjacency_list[i].emplace_back(i + 1, 1);
  }

  Dijkstra dijkstra(0, graph_vertex_number, adjacency_list);

  for (std::uint64_t i = 0; i < graph_vertex_number; ++i) {
    EXPECT_EQ(dijkstra.GetMinimumDistanceToVertex(i), i);
  }
}

TEST(DijkstraTest, MultiplePaths) {
  Dijkstra::AdjacencyListType adjacency_list(4);
  adjacency_list[0].emplace_back(1, 1);
  adjacency_list[0].emplace_back(2, 4);
  adjacency_list[1].emplace_back(2, 2);
  adjacency_list[1].emplace_back(3, 6);
  adjacency_list[2].emplace_back(3, 3);

  Dijkstra dijkstra(0, 4, adjacency_list);

  EXPECT_EQ(dijkstra.GetMinimumDistanceToVertex(0), 0);
  EXPECT_EQ(dijkstra.GetMinimumDistanceToVertex(1), 1);
  EXPECT_EQ(dijkstra.GetMinimumDistanceToVertex(2), 3);
  EXPECT_EQ(dijkstra.GetMinimumDistanceToVertex(3), 6);
}
