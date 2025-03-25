#ifndef WHEELS_UNION_FIND_SET_H
#define WHEELS_UNION_FIND_SET_H

#include <cinttypes>
#include <vector>

class UnionFindSet {
 public:
  using ElementType = std::uintmax_t;
  using SizeType = std::vector<ElementType>::size_type;

  explicit UnionFindSet(SizeType element_number);
  UnionFindSet(const UnionFindSet& other) = default;
  UnionFindSet(UnionFindSet&& other) noexcept = default;
  ~UnionFindSet() = default;
  UnionFindSet& operator=(const UnionFindSet& other) = default;
  UnionFindSet& operator=(UnionFindSet&& other) noexcept;

  void AddSet();
  void Union(const ElementType& element1, const ElementType& element2);
  ElementType Find(const ElementType& element) const;

  [[nodiscard]] SizeType ElementNumber() const noexcept;
  [[nodiscard]] SizeType SetNumber() const noexcept;

  SizeType SetSizeOfElement(const ElementType& element) const noexcept;
  bool IsInOneSet(const ElementType& element1,
                  const ElementType& element2) const;
  bool IsSetRootElement(const ElementType& element) const;

 private:
  void CheckElement(const ElementType& element) const;

  SizeType set_number_;
  mutable std::vector<SizeType> parents_;
  std::vector<SizeType> set_size_;
};

#endif  // WHEELS_UNION_FIND_SET_H
