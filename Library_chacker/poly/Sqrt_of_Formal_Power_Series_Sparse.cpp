#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/math/poly/fps_sqrt.hpp"

// #define tests
using mint = M99;
void Yorisou() {
  LL(N, K);
  vector<mint> a(N);
  FOR(K) {
    INT(i, x);
    a[i] = x;
  }
  a = fps_sqrt_any(a);
  if (a.empty()) return print(-1);
  print(a);
}
#include "YRS/Z_H/main.hpp"