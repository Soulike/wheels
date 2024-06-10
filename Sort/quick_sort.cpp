#include <functional>
#include <random>
#include <vector>

class quick_sort {
 public:
  template <typename RandomIt>
  void operator()(const RandomIt& first, const RandomIt& last) {
    quick_sort_impl(
        first, last,
        std::less_equal<typename std::iterator_traits<RandomIt>::value_type>());
  }

  template <typename RandomIt, typename Compare>
  void operator()(const RandomIt& first,
                  const RandomIt& last,
                  const Compare& comp) {
    quick_sort_impl(first, last, comp);
  }

 private:
  template <typename RandomIt, typename Compare>
  void quick_sort_impl(const RandomIt& first,
                       const RandomIt& last,
                       const Compare& comp) {
    if (first >= last) {
      return;
    }

    int random_range_end = last - first;
    int random_int = generate_random_int(0, random_range_end);
    RandomIt random_it = first + random_int;
    std::iter_swap(first, random_it);

    RandomIt pivot_it = first;
    RandomIt left = first;
    RandomIt right = last - 1;
    while (left < right) {
      while (left < right && !comp(*right, *pivot_it)) {
        right--;
      }
      while (left < right && comp(*left, *pivot_it)) {
        left++;
      }
      std::iter_swap(left, right);
    }
    std::iter_swap(pivot_it, right);

    quick_sort_impl(first, right, comp);
    quick_sort_impl(right + 1, last, comp);
  }

  static int generate_random_int(const int begin, const int end) {
    std::random_device random_device;
    std::mt19937 gen(random_device());
    std::uniform_int_distribution<> distribution(begin, end - 1);
    return distribution(gen);
  }
};