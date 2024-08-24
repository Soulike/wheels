#ifndef WHEELS_FRACTION_H
#define WHEELS_FRACTION_H
#include <cinttypes>
#include <string>

template <typename T>
class Fraction {
 private:
  T _numerator;
  T _dominator;
  std::int8_t _sign;  // 1 or -1

 public:
  Fraction(T numerator, T dominator);
  Fraction operator+(const Fraction& other) const;
  Fraction& operator+=(const Fraction& other);
  Fraction operator-(const Fraction& other) const;
  Fraction& operator-=(const Fraction& other);
  Fraction operator*(const Fraction& other) const;
  Fraction& operator*=(const Fraction& other);
  Fraction operator/(const Fraction& other) const;
  Fraction& operator/=(const Fraction& other);
  std::string toString() const;
  long double toNumber() const;

 private:
  void reduce();
};

#endif  // WHEELS_FRACTION_H
