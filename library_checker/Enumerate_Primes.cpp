#define YRSD
// #include "YRS/aa/fast.hpp"
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
// #include "YRS/ds/basic/retsu.hpp"
// #include "YRS/mod/mint.hpp"
// #include "YRS/aa/def.hpp"
#include "YRS/pr/ptable.hpp"

void Yorisou() {
  INT(N, a, b);
  vc<int> p = ptable(N);
  while (not p.empty() and p.back() > N) pop(p);
  int sz = len(p);
  vc<int> s;
  FOR(i, N + 1) {
    if (i * a + b >= sz) break;
    s.ep(p[i * a + b]);
  }
  print(len(p), len(s));
  print(s);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"