#include "union_find_set.h"

UnionFindSet::UnionFindSet(const SizeType element_number)
    : set_number_(element_number),
      parents_(element_number),
      set_size_(element_number, 1) {
  for (int i = 0; i < element_number; i++) {
    parents_[i] = i;
  }
}

UnionFindSet::SizeType UnionFindSet::ElementNumber() const noexcept {
  return parents_.size();
}

UnionFindSet::SizeType UnionFindSet::SetNumber() const noexcept {
  return set_number_;
}

void UnionFindSet::AddSet() {
  set_number_++;
  const ElementType set_element = parents_.size();
  parents_.push_back(set_element);
  set_size_[set_element] = 1;
}


void UnionFindSet::Union(const ElementType& element1,
                         const ElementType& element2) {
  CheckElement(element1);
  CheckElement(element2);
  if (IsInOneSet(element1, element2)) {
    return;
  }
  const ElementType set_a = Find(element1);
  const ElementType set_b = Find(element2);
  set_number_--;
  parents_[set_b] = set_a;
  set_size_[set_a] += set_size_[set_b];
  set_size_[set_b] = 0;
}

bool UnionFindSet::IsInOneSet(const ElementType& element1,
                              const ElementType& element2) const {
  CheckElement(element1);
  CheckElement(element2);
  return Find(element1) == Find(element2);
}

UnionFindSet::ElementType UnionFindSet::Find(const ElementType& element) const {
  CheckElement(element);
  ElementType current_element = element;
  while (parents_[current_element] != current_element) {
    parents_[current_element] = parents_[parents_[current_element]];
    current_element = parents_[current_element];
  }
  return current_element;
}

UnionFindSet::SizeType UnionFindSet::SetSizeOfElement(
    const ElementType& element) const noexcept {
  CheckElement(element);
  const ElementType root = Find(element);
  return set_size_[root];
}

bool UnionFindSet::IsSetRootElement(const ElementType& element) const {
  CheckElement(element);
  return parents_[element] == element;
}

void UnionFindSet::CheckElement(const ElementType& element) const {
  if (element >= parents_.size()) {
    std::abort();
  }
}
