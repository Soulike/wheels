#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <iterator>

template <typename RandomAccessIterator,
          typename T =
              typename std::iterator_traits<RandomAccessIterator>::value_type>
RandomAccessIterator binarySearch(RandomAccessIterator begin,
                                  RandomAccessIterator end,
                                  const T& target) {
  auto left = begin;
  auto right = end;
  while (left < right) {
    auto mid = (right - left) / 2 + left;
    if (*mid < target) {
      left = mid + 1;
    } else if (*mid > target) {
      right = mid;
    } else {
      // *mid == target
      return mid;
    }
  }

  return end;
}

/**
 * Find the first element > target. If not found, returns end.
 */
template <typename RandomAccessIterator,
          typename T =
              typename std::iterator_traits<RandomAccessIterator>::value_type>
RandomAccessIterator upperBound(RandomAccessIterator begin,
                                RandomAccessIterator end,
                                const T& target) {
  // Search range is [left, right)
  auto left = begin;
  auto right = end;

  while (left < right) {
    auto mid = (right - left) / 2 + left;
    if (*mid <= target) {
      left = mid + 1;
    } else {
      // *mid > target

      // If *mid > target, it is possible that also *(mid - 1) > target.
      // So next range is [left, mid)
      // If *(mid - 1) <= target, then left will eventually become mid, i.e.,
      // left == right, and mid is returned.
      right = mid;
    }
  }

  return left;
}

/**
 * Find the first element >= target. If not found, returns end.
 */
template <typename RandomAccessIterator,
          typename T =
              typename std::iterator_traits<RandomAccessIterator>::value_type>
RandomAccessIterator lowerBound(RandomAccessIterator begin,
                                RandomAccessIterator end,
                                const T& target) {
  auto left = begin;
  auto right = end;

  while (left < right) {
    auto mid = (right - left) / 2 + left;
    if (*mid >= target) {
      right = mid;
    } else {
      // *mid < target
      left = mid + 1;
    }
  }

  return left;
}

#endif  // BINARY_SEARCH_H
