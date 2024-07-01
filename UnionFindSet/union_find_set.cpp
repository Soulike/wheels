#include "union_find_set.h"

union_find_set::union_find_set(union_find_set::size_type n) {
  _parents.resize(n);
  for (int i = 0; i < n; i++) {
    _parents[i] = i;
  }
  _set_count = n;
}

union_find_set::union_find_set(const union_find_set& other)
    : _set_count(other._set_count), _parents(other._parents) {}

union_find_set::union_find_set(union_find_set&& other) noexcept
    : _set_count(other._set_count), _parents(std::move(other._parents)) {}

union_find_set& union_find_set::operator=(const union_find_set& other) {
  this->_set_count = other._set_count;
  this->_parents = other._parents;
}

union_find_set& union_find_set::operator=(union_find_set&& other) noexcept {
  this->_set_count = other._set_count;
  this->_parents = std::move(other._parents);
}

union_find_set::size_type union_find_set::size() const noexcept {
  return _parents.size();
}

union_find_set::size_type union_find_set::set_count() noexcept {
  return _set_count;
}

void union_find_set::do_union(const element_type& element1,
                              const element_type& element2) {
  element_type set_a = find(element1);
  element_type set_b = find(element2);
  if (set_a != set_b) {
    _set_count--;
    _parents[set_b] = set_a;
  }
}

bool union_find_set::is_in_one_set(const element_type& element1,
                                   const element_type& element2) {
  return find(element1) == find(element2);
}

union_find_set::element_type union_find_set::find(const element_type& element) {
  element_type current_element = element;
  while (_parents[current_element] != current_element) {
    current_element = _parents[current_element];
    _parents[current_element] = find(_parents[current_element]);
  }
  return current_element;
}
