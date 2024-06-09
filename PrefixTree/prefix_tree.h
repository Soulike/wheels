#ifndef WHEELS_PREFIX_TREE_H
#define WHEELS_PREFIX_TREE_H

#include <memory>
#include <string>

class prefix_tree {
 private:
  class node_type;
  std::shared_ptr<node_type> _root;

 public:
  prefix_tree() noexcept;
  prefix_tree(prefix_tree& other) noexcept;
  prefix_tree(prefix_tree&& other) noexcept;
  ~prefix_tree() = default;
  prefix_tree& operator=(prefix_tree const& other) noexcept;
  prefix_tree& operator=(prefix_tree&& other) noexcept;
  void insert_word(const std::string& word);
  bool search_word(const std::string& word) const;
  std::string get_shortest_match_prefix(const std::string& word) const;
  void clear() noexcept;
};

#endif  // WHEELS_PREFIX_TREE_H
