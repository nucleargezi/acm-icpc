#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/math/poly/fps_pow.hpp"

// #define tests
using mint = M99;
void Yorisou() {
  LL(N, K, M);
  vector<mint> a(N);
  FOR(K) {
    INT(i, x);
    a[i] = x;
  }
  print(fps_pow(a, M));
}
#include "YRS/Z_H/main.hpp"