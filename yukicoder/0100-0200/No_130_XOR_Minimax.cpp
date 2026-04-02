#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
// #include "YRS/ds/basic/retsu.hpp"
// #include "YRS/mod/mint.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N);
  VEC(int, a, N);
  Z f = [&](Z &f, int k, const vc<int> &a) -> int {
    if (k == -1) return 0;
    vc<int> l, r;
    for (int x : a) ((x >> k & 1) ? l : r).ep(x);
    if (l.empty()) return f(f, k - 1, r);
    if (r.empty()) return f(f, k - 1, l);
    return 1 << k | min(f(f, k - 1, l), f(f, k - 1, r));
  };
  print(f(f, 30, a));
}
#include "YRS/aa/main.hpp"