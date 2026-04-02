#define YRSD
// #include "YRS/aa/fast.hpp"
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
// #include "YRS/ds/basic/retsu.hpp"
// #include "YRS/mod/mint.hpp"
// #include "YRS/aa/def.hpp"

void Yorisou() {
  VEC(int, a, 3);
  STR(str);
  int c[3]{};
  for (char x : str) c[x == 'G' ? 0 : x == 'C' ? 1 : 2] += 1;
  int s = 0;
  FOR(i, 3) {
    int d = min(a[i], c[(i + 1) % 3]);
    a[i] -= d;
    c[(i + 1) % 3] -= d;
    s += 3 * d;
  }
  FOR(i, 3) s += min(a[i], c[i]);
  print(s);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"