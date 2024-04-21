class union_find_set {
 public:
  using element_type = unsigned long long;
  using size_type = unsigned long long;

 private:
  size_type _set_count;
  const size_type _size;
  element_type* const parent;

 public:
  union_find_set(size_type n) : _size(n), parent(new element_type[n]) {
    for (int i = 0; i < n; i++) {
      parent[i] = i;
    }
    _set_count = n;
  }

  ~union_find_set() { delete[] parent; }

  size_type size() const { return _size; }

  size_type set_count() const { return _set_count; }

  void do_union(element_type element1, element_type element2) {
    element_type aSet = find(element1);
    element_type bSet = find(element2);
    if (aSet != bSet) {
      _set_count--;
      parent[bSet] = aSet;
    }
  }

  bool isInOneSet(element_type element1, element_type element2) {
    return find(element1) == find(element2);
  }

 private:
  element_type find(element_type element) {
    element_type currentMember = element;
    while (parent[currentMember] != currentMember) {
      currentMember = parent[currentMember];
      parent[currentMember] = find(parent[currentMember]);
    }
    return currentMember;
  }
};