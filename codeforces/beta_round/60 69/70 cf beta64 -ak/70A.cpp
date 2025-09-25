#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/math/mod/modint.hpp"

// #define tests
using mint = modint<1'000'003>;
void Yorisou() {
  INT(N);
  print(mint(3).pow(N - 1));
}
#include "YRS/Z_H/main.hpp"