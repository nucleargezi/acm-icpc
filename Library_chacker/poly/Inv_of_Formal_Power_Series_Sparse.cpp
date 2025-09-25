#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/math/poly/fps_inv.hpp"

// #define tests
using mint = M99;
void Yorisou() {
  INT(N, K);
  vector<mint> a(N);
  FOR(K) {
    INT(i, x);
    a[i] = x;
  }
  print(fps_inv(a));
}
#include "YRS/Z_H/main.hpp"