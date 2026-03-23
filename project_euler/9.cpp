#include "YRS/all.hpp"
#include "YRS/nt/enum_pytagorean_triple.hpp"

void Yorisou() {
  for (Z [a, b, c] : enum_pytagorean_triple<0>(1000)) {
    if (a + b + c == 1000) print(a * b * c);
  }
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"