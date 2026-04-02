#define YRSD
// #include "YRS/aa/fast.hpp"
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
// #include "YRS/ds/basic/retsu.hpp"
// #include "YRS/mod/mint.hpp"
// #include "YRS/aa/def.hpp"

using re = double;
void Yorisou() {
  INT(A);
  A = 80 - A;
  VEC(int, p, 3);
  
  constexpr int n = 14;
  vc<tuple<int, int, re>> upd;
  FOR(s, 1 << n) FOR_subset(sb, s) {
    re g = 1;
    FOR(i, n) if (s >> i & 1) {
      int c = 0;
      c += i != 0 and (s >> (i - 1) & 1);
      c += i + 1 != n and (s >> (i + 1) & 1);
      if (sb >> i & 1)  g *= (1 - p[c] / 100.l);
      else  g *= p[c] / 100.l;
    }
    upd.ep(s, sb, g);
  }
  vc<re> dp(1 << n), ndp(dp);
  end(dp)[-1] = 1;
  FOR(A) {
    fill(all(ndp), 0);
    for (Z [f, t, w] : upd) ndp[t] += dp[f] * w;
    dp.swap(ndp);
  }
  re s = 0;
  FOR(i, 1 << n) s += pc(i) * dp[i];
  setp(10);
  print(2 * s);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"