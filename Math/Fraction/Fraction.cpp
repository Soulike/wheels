#include "Fraction.h"
#include "../math.h"

template <typename T>
Fraction<T>::Fraction(T numerator, T dominator)
    : _numerator(std::abs(numerator)),
      _dominator(std::abs(dominator)),
      _sign(isInDifferentSign(numerator, dominator) ? -1 : 1){};

template <typename T>
Fraction<T> Fraction<T>::operator+(const Fraction& other) const {
  const T newDominator = other._dominator * _dominator;
  const T newNumerator = other._dominator * _numerator * _sign +
                         _dominator * other._numerator * other._sign;
  Fraction fraction(newNumerator, newDominator);
  fraction.reduce();
  return fraction;
}

template <typename T>
Fraction<T>& Fraction<T>::operator+=(const Fraction& other) {
  const T dominator = other._dominator * _dominator;
  const T numerator = other._dominator * _numerator * _sign +
                      _dominator * other._numerator * other._sign;
  _numerator = std::abs(numerator);
  _dominator = std::abs(dominator);
  _sign = isInDifferentSign(numerator, dominator) ? -1 : 1;
  reduce();
  return *this;
}

template <typename T>
Fraction<T> Fraction<T>::operator-(const Fraction& other) const {
  const T newDominator = other._dominator * _dominator;
  const T newNumerator = other._dominator * _numerator * _sign -
                         _dominator * other._numerator * other._sign;
  Fraction fraction(newNumerator, newDominator);
  fraction.reduce();
  return fraction;
}

template <typename T>
Fraction<T>& Fraction<T>::operator-=(const Fraction& other) {
  const T dominator = other._dominator * _dominator;
  const T numerator = other._dominator * _numerator * _sign -
                      _dominator * other._numerator * other._sign;
  _numerator = std::abs(numerator);
  _dominator = std::abs(dominator);
  _sign = isInDifferentSign(numerator, dominator) ? -1 : 1;
  reduce();
  return *this;
}

template <typename T>
Fraction<T> Fraction<T>::operator*(const Fraction& other) const {
  const T dominator = _dominator * other._dominator;
  const T numerator = _numerator * other._numerator * _sign * other._sign;
  return {numerator, dominator};
}

template <typename T>
Fraction<T>& Fraction<T>::operator*=(const Fraction& other) {
  _dominator *= other._dominator;
  _numerator *= other._numerator;
  _sign *= other._sign;
  return *this;
}

template <typename T>
Fraction<T> Fraction<T>::operator/(const Fraction& other) const {
  const T dominator = _dominator * other._numerator;
  const T numerator = _numerator * other._dominator * _sign * other._sign;
  return {numerator, dominator};
}

template <typename T>
Fraction<T>& Fraction<T>::operator/=(const Fraction& other) {
  _dominator *= other._numerator;
  _numerator *= other._dominator;
  _sign *= other._sign;
  return *this;
}

template <typename T>
std::string Fraction<T>::toString() const {
  std::string result;
  if (_sign == -1) {
    result += '-';
  }
  result += std::to_string(_numerator);
  result += '/';
  result += std::to_string(_dominator);
  return result;
}

template <typename T>
long double Fraction<T>::toNumber() const {
  return _numerator / _dominator * _sign;
}

template <typename T>
void Fraction<T>::reduce() {
  if (_numerator == 0) {
    _dominator = 1;
    _sign = 1;
    return;
  }

  T greatestCommonDivisor = getGreatestCommonDivisor(_numerator, _dominator);
  while (greatestCommonDivisor > 1) {
    _numerator /= greatestCommonDivisor;
    _dominator /= greatestCommonDivisor;
    greatestCommonDivisor = getGreatestCommonDivisor(_numerator, _dominator);
  }
}
