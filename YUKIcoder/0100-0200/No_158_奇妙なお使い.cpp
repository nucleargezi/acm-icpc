#define YRSD
// #include "YRS/aa/fast.hpp"
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
// #include "YRS/ds/basic/retsu.hpp"
// #include "YRS/mod/mint.hpp"
// #include "YRS/aa/def.hpp"

using T = T3<int>;
void Yorisou() {
  INT(a, b, c);
  vc<pair<int, T>> bc(2);
  IN(bc);
  map<PII, int> dp, ndp;
  
  dp[{a, b}] = c;
  int s = 0;
  while (not dp.empty()) {
    ++s;
    ndp.clear();
    for (Z [p, z] : dp) {
      Z [x, y] = p;
      for (Z [d, a] : bc) {
        Z [e, r, t] = a;
        FOR(i, x + 1) FOR(k, y + 1) {
          int w = i * 1000 + k * 100;
          if (w > d) break;
          if (d - w > z) continue;
          chmax(ndp[{x - i + e, y - k + r}], z - (d - w) + t);
        }
      }
    }
    dp.swap(ndp);
  }
  print(s - 1);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"