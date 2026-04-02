#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
// #include "YRS/ds/basic/retsu.hpp"
// #include "YRS/mod/mint.hpp"

void Yorisou() {
  INT(N, L);
  VEC(T3<int>, a, N);
  int T = 0, f = 0;
  for (Z [l, w, t] : a) {
    T += l - f;
    int r = T % (2 * t);
    if (r >= t or r + w > t) T += 2 * t - r;
    T += w;
    f = l + w;
  }
  print(T + L - f);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"