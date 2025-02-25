#include "combination.h"

std::uintmax_t combination(const std::uintmax_t totalNumber,
                           const std::uintmax_t selectionNumber) {
  std::uintmax_t result = 1;
  for (std::uintmax_t i = 1; i <= (totalNumber - selectionNumber); i++) {
    result *= (selectionNumber + i);
    result /= i;
  }
  return result;
}
