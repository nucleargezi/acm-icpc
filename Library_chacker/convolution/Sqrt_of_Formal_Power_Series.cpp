#include "YRS/Z_H/MeioN.hpp"
#include "YRS/MeIoN_all.hpp"
#include "YRS/math/poly/fps_sqrt.hpp"

// #define tests
using mint = M99;
void Yorisou() {
  INT(n);
  VEC(mint, a, n);
  vector ans = fps_sqrt_any(a);
  if (len(ans) != n) {
    UL(-1);
  } else {
    UL(ans);
  }
}
#include "YRS/Z_H/main.hpp"