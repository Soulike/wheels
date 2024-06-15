#include "heap.h"

template <typename T, typename Comp>
template <typename Iter, typename>
heap<T, Comp>::heap(const Iter& begin, const Iter& end, const Comp& comp)
    : container(std::vector<T>(begin, end)), comp(comp) {
  heapify(container, comp);
}

template <typename T, typename Comp>
heap<T, Comp>::heap(const Comp& comp) : comp(comp) {}

template <typename T, typename Comp>
void heap<T, Comp>::push(const T& value) {
  container.push_back(value);
  back_shift_up(container, comp);
}

template <typename T, typename Comp>
void heap<T, Comp>::push(const T&& value) {
  container.push_back(value);
  back_shift_up(container, comp);
}

template <typename T, typename Comp>
void heap<T, Comp>::pop() {
  std::swap(container.front(), container.back());
  container.pop_back();
  shift_down(container, 0, comp);
}

template <typename T, typename Comp>
T& heap<T, Comp>::top() {
  return container.front();
}

template <typename T, typename Comp>
typename std::vector<T>::size_type heap<T, Comp>::size() const noexcept {
  return container.size();
}

template <typename T, typename Comp>
bool heap<T, Comp>::empty() const noexcept {
  return container.empty();
}

template <typename T, typename Comp>
void heap<T, Comp>::heapify(decltype(heap<T, Comp>::container)& container,
                            const decltype(heap<T, Comp>::comp)& comp) {
  if (container.empty()) {
    return;
  }

  const auto last_index = container.size() - 1;
  const auto last_parent_index = get_parent_index(last_index);

  for (int parent_index = last_parent_index; parent_index >= 0;
       parent_index--) {
    shift_down(container, parent_index, comp);
  }
}

template <typename T, typename Comp>
void heap<T, Comp>::shift_down(decltype(heap<T, Comp>::container)& container,
                               heap::index_type index,
                               const decltype(heap<T, Comp>::comp)& comp) {
  index_type current_index = index;
  while (true) {
    const auto left_child_index = get_left_child_index(current_index);
    const auto right_child_index = get_right_child_index(current_index);
    int largest_child_index = current_index;

    if (left_child_index < container.size() &&
        comp(container[largest_child_index], container[left_child_index])) {
      largest_child_index = left_child_index;
    }

    if (right_child_index < container.size() &&
        comp(container[largest_child_index], container[right_child_index])) {
      largest_child_index = right_child_index;
    }

    if (largest_child_index != current_index) {
      std::swap(container[current_index], container[largest_child_index]);
      current_index = largest_child_index;
    } else {
      break;
    }
  }
}

template <typename T, typename Comp>
void heap<T, Comp>::back_shift_up(decltype(heap<T, Comp>::container)& container,
                                  const decltype(heap<T, Comp>::comp)& comp) {
  if (container.empty()) {
    return;
  }
  index_type current_index = container.size() - 1;
  while (true) {
    if (current_index == 0) {
      break;
    }
    const auto parent_index = get_parent_index(current_index);
    if (comp(container[parent_index], container[current_index])) {
      std::swap(container[parent_index], container[current_index]);
      current_index = parent_index;
    } else {
      break;
    }
  }
}

template <typename T, typename Comp>
constexpr heap<T, Comp>::index_type heap<T, Comp>::get_parent_index(
    const heap::index_type child_index) noexcept {
  if (child_index % 2) {
    return (child_index - 1) / 2;
  } else {
    return (child_index - 2) / 2;
  }
}

template <typename T, typename Comp>
constexpr heap<T, Comp>::index_type heap<T, Comp>::get_left_child_index(
    heap::index_type parent_index) noexcept {
  return parent_index * 2 + 1;
}

template <typename T, typename Comp>
constexpr heap<T, Comp>::index_type heap<T, Comp>::get_right_child_index(
    heap::index_type parent_index) noexcept {
  return parent_index * 2 + 2;
}