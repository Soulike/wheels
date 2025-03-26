#ifndef GET_NTH_ELEMENT_H
#define GET_NTH_ELEMENT_H

#include <algorithm>
#include <cinttypes>
#include <functional>

// `n` starts with 0.
template <typename RandomIterator>
RandomIterator GetNthElement(const std::uint64_t& n,
                             const RandomIterator& begin,
                             const RandomIterator& end) {
  std::function<RandomIterator(RandomIterator, RandomIterator)> impl =
      [&](const RandomIterator range_begin, const RandomIterator range_end) {
        if (range_begin >= range_end) {
          return end;
        }

        RandomIterator left = range_begin;
        RandomIterator right = range_end - 1;

        const auto pivot = *range_begin;

        while (left < right) {
          while (left < right && *right >= pivot) {
            right--;
          }
          while (left < right && *left <= pivot) {
            left++;
          }

          std::swap(*left, *right);
        }

        std::swap(*range_begin, *right);

        const auto current_pivot_position = right - begin;

        if (current_pivot_position == n) {
          return right;
        } else if (current_pivot_position < n) {
          return impl(right + 1, range_end);
        } else {
          return impl(range_begin, right);
        }
      };

  return impl(begin, end);
}

#endif  // GET_NTH_ELEMENT_H
