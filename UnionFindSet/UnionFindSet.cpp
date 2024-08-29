#include "UnionFindSet.h"

UnionFindSet::UnionFindSet(UnionFindSet::SizeType n) {
  _parents.resize(n);
  for (int i = 0; i < n; i++) {
    _parents[i] = i;
  }
  _setCount = n;
}

UnionFindSet::UnionFindSet(const UnionFindSet& other) = default;

UnionFindSet::UnionFindSet(UnionFindSet&& other) noexcept = default;

UnionFindSet& UnionFindSet::operator=(const UnionFindSet& other) = default;

UnionFindSet& UnionFindSet::operator=(UnionFindSet&& other) noexcept = default;

UnionFindSet::SizeType UnionFindSet::elementCount() const noexcept {
  return _parents.size();
}

UnionFindSet::SizeType UnionFindSet::setCount() const noexcept {
  return _setCount;
}

void UnionFindSet::doUnion(const ElementType& element1,
                           const ElementType& element2) {
  ElementType set_a = find(element1);
  ElementType set_b = find(element2);
  if (set_a != set_b) {
    _setCount--;
    _parents[set_b] = set_a;
  }
}

bool UnionFindSet::isInOneSet(const ElementType& element1,
                              const ElementType& element2) {
  return find(element1) == find(element2);
}

UnionFindSet::ElementType UnionFindSet::find(const ElementType& element) {
  ElementType current_element = element;
  while (_parents[current_element] != current_element) {
    current_element = _parents[current_element];
    _parents[current_element] = find(_parents[current_element]);
  }
  return current_element;
}

UnionFindSet::SizeType UnionFindSet::setSize(
    const UnionFindSet::ElementType& element) noexcept {
  const ElementType root = find(element);
  return _setSize[root];
}

bool UnionFindSet::isSetRootElement(const ElementType& element) {
  return find(element) == element;
}
