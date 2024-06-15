#ifndef WHEELS_HEAP_H
#define WHEELS_HEAP_H
#include <vector>

template <typename T, typename Comp>
class heap {
 public:
  using index_type = std::vector<T>::size_type;
  using size_type = index_type;

  explicit heap(const Comp& comp = std::less<T>());
  template <typename Iter,
            typename = std::enable_if_t<
                std::is_same<typename std::iterator_traits<Iter>::value_type,
                             T>::value>>
  heap(const Iter& begin, const Iter& end, const Comp& comp);

  void push(const T& value);
  void push(const T&& value);
  void pop();
  T& top();
  size_type size() const noexcept;
  bool empty() const noexcept;

 private:
  std::vector<T> container;
  const Comp comp;

  static void heapify(decltype(heap<T, Comp>::container)& container,
                      const decltype(heap<T, Comp>::comp)& comp);
  static void shift_down(decltype(heap<T, Comp>::container)& container,
                         index_type index,
                         const decltype(heap<T, Comp>::comp)& comp);
  static void back_shift_up(decltype(heap<T, Comp>::container)& container,
                            const decltype(heap<T, Comp>::comp)& comp);
  static constexpr index_type get_parent_index(index_type child_index) noexcept;
  static constexpr index_type get_left_child_index(
      index_type parent_index) noexcept;
  static constexpr index_type get_right_child_index(
      index_type parent_index) noexcept;
};
#endif  // WHEELS_HEAP_H
