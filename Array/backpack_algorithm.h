#ifndef BACKPACK_ALGORITHM_H
#define BACKPACK_ALGORITHM_H

#include <cstdint>
#include <vector>

std::uint64_t Knapsack(std::uint64_t capacity,
                       std::uint64_t n,
                       const std::vector<std::uint64_t>& weights,
                       const std::vector<std::uint64_t>& values);

#endif  // BACKPACK_ALGORITHM_H
