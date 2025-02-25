#include "combination.h"

#include <algorithm>

std::uintmax_t combination(std::uintmax_t totalNumber,
                           std::uintmax_t selectionNumber) {
  std::uintmax_t result = 1;
  selectionNumber = std::max(selectionNumber, totalNumber - selectionNumber);
  for (std::uintmax_t i = 1; i <= totalNumber - selectionNumber; i++) {
    result *= (selectionNumber + i);
    result /= i;
  }
  return result;
}
