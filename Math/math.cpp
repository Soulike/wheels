#include "math.h"
#include <algorithm>

template <typename T>
T getGreatestCommonDivisor(const T num1, const T num2) {
  T divided = std::max(num1, num2);
  T divisor = std::min(num1, num2);

  while (divisor > 0) {
    T remainder = divided % divisor;
    divided = divisor;
    divisor = remainder;
  }
  return divided;
}

template <typename T>
bool isInOppositeSign(const T num1, const T num2) {
  return (num1 ^ num2) < 0;
}
