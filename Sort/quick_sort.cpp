#include <functional>
#include <iterator>
#include <random>

class quick_sort_impl {
 public:
  template <typename RandomIt, typename Compare>
  static void sort(const RandomIt& first,
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

    sort(first, right, comp);
    sort(right + 1, last, comp);
  }

 private:
  static int generate_random_int(const int begin, const int end) {
    std::random_device random_device;
    std::mt19937 gen(random_device());
    std::uniform_int_distribution<> distribution(begin, end - 1);
    return distribution(gen);
  }
};

template <typename RandomIt, typename Compare>
void quick_sort(const RandomIt& first,
                const RandomIt& last,
                const Compare& comp) {
  return quick_sort_impl::sort(first, last, comp);
}

template <typename RandomIt>
void quick_sort(const RandomIt& first, const RandomIt& last) {
  return quick_sort_impl::sort(first, last,
                               std::less<std::iter_value_t<RandomIt>>());
}