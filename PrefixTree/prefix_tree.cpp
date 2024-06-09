#include "prefix_tree.h"
#include <memory>
#include <unordered_map>

class prefix_tree::node_type {
 private:
  char _character;
  bool _is_end;
  std::unordered_map<char, std::shared_ptr<node_type>> _character_to_childs;

 public:
  node_type(char character, bool is_end) noexcept
      : _character(character), _is_end(is_end) {}

  node_type(node_type& other) noexcept
      : _character(other._character), _is_end(other._is_end) {
    for (const auto& character_to_child : other._character_to_childs) {
      _character_to_childs[character_to_child.first] =
          std::make_shared<node_type>(*character_to_child.second);
    }
  }

  node_type(node_type&& other) noexcept
      : _character(other._character),
        _is_end(other._is_end),
        _character_to_childs(std::move(other._character_to_childs)) {}

  ~node_type() = default;

  node_type& operator=(node_type const& other) noexcept {
    if (&other == this) {
      return *this;
    }
    _character = other._character;
    _is_end = other._is_end;
    for (const auto& character_to_child : other._character_to_childs) {
      _character_to_childs[character_to_child.first] =
          std::make_shared<node_type>(*character_to_child.second);
    }
    return *this;
  }

  node_type& operator=(node_type&& other) noexcept {
    if (&other == this) {
      return *this;
    }
    _character = other._character;
    _is_end = other._is_end;
    _character_to_childs = std::move(other._character_to_childs);
    return *this;
  }

  void append_child(char character, bool is_end) {
    auto new_child = std::make_shared<node_type>(character, is_end);
    _character_to_childs.insert({character, new_child});
  }

  bool match(char character) const noexcept { return _character == character; }

  bool is_end() const noexcept { return _is_end; }

  void set_is_end() noexcept { _is_end = true; }

  std::shared_ptr<node_type> find_child(char character) const {
    if (_character_to_childs.count(character)) {
      return _character_to_childs.at(character);
    } else {
      return nullptr;
    }
  }
};

prefix_tree::prefix_tree() noexcept
    : _root(std::make_shared<node_type>('\0', false)) {}

prefix_tree::prefix_tree(prefix_tree& other) noexcept
    : _root(std::make_shared<node_type>(*other._root)) {}

prefix_tree::prefix_tree(prefix_tree&& other) noexcept
    : _root(std::move(other._root)) {}

prefix_tree& prefix_tree::operator=(prefix_tree const& other) noexcept {
  if (&other == this) {
    return *this;
  }
  _root = std::make_shared<node_type>(*other._root);
  return *this;
}

prefix_tree& prefix_tree::operator=(prefix_tree&& other) noexcept {
  if (&other == this) {
    return *this;
  }
  _root = std::move(other._root);
  return *this;
}

void prefix_tree::insert_word(const std::string& word) {
  auto current_node = _root;
  for (int i = 0; i < word.size(); i++) {
    auto child_node = current_node->find_child(word[i]);
    if (!child_node) {
      current_node->append_child(word[i], i == word.size() - 1);
      child_node = current_node->find_child(word[i]);
    }
    current_node = child_node;
  }

  current_node->set_is_end();
}

bool prefix_tree::search_word(const std::string& word) const {
  auto current_node = _root;
  for (char character : word) {
    auto child_node = current_node->find_child(character);
    if (!child_node) {
      return false;
    }
    current_node = child_node;
  }

  return current_node->is_end();
}

std::string prefix_tree::get_shortest_match_prefix(
    const std::string& word) const {
  auto current_node = _root;
  for (int i = 0; i < word.size(); i++) {
    if (current_node->is_end()) {
      return word.substr(0, i);
    }
    auto child_node = current_node->find_child(word[i]);
    if (!child_node) {
      return "";
    }
    current_node = child_node;
  }

  return current_node->is_end() ? word : "";
}

void prefix_tree::clear() noexcept {
  _root = std::make_shared<node_type>('\0', false);
}