#ifndef WHEELS_UNION_FIND_SET_H
#define WHEELS_UNION_FIND_SET_H
#include <vector>

class UnionFindSet {
 public:
  using ElementType = unsigned long long;
  using SizeType = std::vector<ElementType>::size_type;

  explicit UnionFindSet(SizeType n);
  UnionFindSet(const UnionFindSet& other);
  UnionFindSet(UnionFindSet&& other) noexcept;
  ~UnionFindSet() = default;

  UnionFindSet& operator=(const UnionFindSet& other);
  UnionFindSet& operator=(UnionFindSet&& other) noexcept;

  SizeType elementCount() const noexcept;
  SizeType setCount() const noexcept;
  SizeType setSize(const ElementType& element) noexcept;
  void doUnion(const ElementType& element1, const ElementType& element2);
  bool isInOneSet(const ElementType& element1, const ElementType& element2);
  bool isSetRootElement(const ElementType& element);

 private:
  SizeType _setCount;
  std::vector<SizeType> _parents;
  std::vector<SizeType> _setSize;

  ElementType find(const ElementType& element);
};

#endif  // WHEELS_UNION_FIND_SET_H
