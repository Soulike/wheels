#ifndef WHEELS_UNION_FIND_SET_H
#define WHEELS_UNION_FIND_SET_H
#include <vector>

class union_find_set {
 public:
  using element_type = unsigned long long;
  using size_type = std::vector<element_type>::size_type;

  explicit union_find_set(size_type n);
  union_find_set(const union_find_set& other);
  union_find_set(union_find_set&& other) noexcept;
  ~union_find_set() = default;

  union_find_set& operator=(const union_find_set& other);
  union_find_set& operator=(union_find_set&& other) noexcept;

  size_type size() const noexcept;
  size_type set_count() noexcept;
  void do_union(const element_type& element1, const element_type& element2);
  bool is_in_one_set(const element_type& element1,
                     const element_type& element2);

 private:
  size_type _set_count;
  std::vector<size_type> _parents;

  element_type find(const element_type& element);
};

#endif  // WHEELS_UNION_FIND_SET_H
