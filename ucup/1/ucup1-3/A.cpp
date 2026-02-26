#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
#include "YRS/random/rng.hpp"
#include "YRS/ds/basic/hashmap.hpp"
#include "YRS/mod/modint.hpp"

#define tests 1
#define fl 0
#define DB 10
using P = pair<string, string>;
using M0 = M99;
using M1 = M17;
void Yorisou() {
  INT(N);
  VEC(P, s, N);
  int A = 0, B = 0, C = 0, ans = 0;
  for (int x = N; x; x /= 10) ++C;
  ans = C;
  int bs = rng(114514);
  Z ck = [&](int a, int b, int c) -> void {
    if (a + b + c >= ans) return;
    hash_map<int> mp;
    int g = 1;
    FOR(c) g *= 10;
    FOR(i, N) {
      M0 x;
      M1 y;
      FOR(k, min<ll>(a, len(s[i].fi))) {
        x = x * bs + s[i].fi[k];
        y = y * bs + s[i].fi[k];
      }
      FOR(k, min<ll>(b, len(s[i].se))) {
        x = x * bs + s[i].se[k];
        y = y * bs + s[i].se[k];
      }
      ++mp[ull(x.val) << 32 | y.val];
    }
    bool o = 1;
    mp.enumerate_all([&](ull ke, int c) -> void { o &= c <= g; });
    if (o) chmin(ans, a + b + c), A = a, B = b, C = c;
  };
  FOR(a, ans + 1) FOR(b, ans + 1) FOR(c, ans + 1) if (a or b or c) ck(a, b, c);
  print(A, B, C);
}
#include "YRS/aa/main.hpp"