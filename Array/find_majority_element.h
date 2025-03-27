#ifndef FIND_MAJORITY_ELEMENT_H
#define FIND_MAJORITY_ELEMENT_H
#include <optional>

/**
 * Boyer–Moore majority vote algorithm
 */
template <typename ForwardIterator>
std::optional<typename std::iterator_traits<ForwardIterator>::value_type>
FindMajorityElement(ForwardIterator begin, ForwardIterator end) {
  ForwardIterator current_element_it = begin;
  std::uintmax_t current_element_vote = 0;
  std::uintmax_t element_number = 0;

  for (auto it = begin; it != end; it++) {
    element_number++;
    if (*it == *current_element_it) {
      current_element_vote++;
    } else {
      current_element_vote--;
      if (current_element_vote == 0) {
        current_element_it = it;
        current_element_vote = 1;
      }
    }
  }

  const auto& possible_majority_element = *current_element_it;
  std::uintmax_t possible_majority_element_number = 0;

  for (auto it = begin; it != end; it++) {
    if (*it == possible_majority_element) {
      possible_majority_element_number++;
      if (possible_majority_element_number > element_number / 2) {
        return *it;
      }
    }
  }

  return std::nullopt;
}

#endif  // FIND_MAJORITY_ELEMENT_H
