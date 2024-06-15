#include <iterator>
#include "../Heap/heap.cpp"
#include "../Heap/heap.h"

template <typename Iter, typename Comp>
void heap_sort(Iter begin,
               const Iter& end,
               const Comp& comp = std::less<std::iter_value_t<Iter>>()) {
  using value_type = std::iter_value_t<Iter>;
  const auto sortComp = [&](const auto& v1, const auto& v2) {
    return comp(v2, v1);
  };
  heap<value_type, decltype(sortComp)> heap(begin, end, sortComp);
  Iter current = begin;
  while (current != end) {
    *current = heap.top();
    heap.pop();
    current++;
  }
}

template <typename Iter>
void heap_sort(Iter begin, const Iter& end) {
  return heap_sort(begin, end, std::less<std::iter_value_t<Iter>>());
}