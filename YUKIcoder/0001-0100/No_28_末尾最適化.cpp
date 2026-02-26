#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/mod/mint.hpp"
#include "YRS/pr/factors.hpp"
#include "YRS/pr/lpf_table.hpp"

#define tests 1
#define fl 0
#define DB 10
using mint = mint_t<1'000'000'09>;
Z lpf = lpf_table(100);
void Yorisou() {
  INT(s, N, K, B);
  ++N;
  vc<int> a(N);
  a[0] = s;
  FOR(i, 1, N) {
    a[i] = (mint(a[i - 1]) * a[i - 1] + mint(a[i - 1]) * 12345 + 1).val();
  }
  Z fa = factor_by_lpf(B, lpf);
  int sz = len(fa);
  Z f = [&](vc<int> f) -> int {
    vc<int> c(sz);
    for (int x : f) FOR(i, sz) {
      while (x % fa[i].fi == 0) ++c[i], x /= fa[i].fi;
    }
    int re = inf<int>;
    FOR(i, sz) chmin(re, c[i] / fa[i].se);
    return re;
  };
  Z fp = [&](int x, int e) {
    int s = 0;
    while (x % e == 0) ++s, x /= e;
    return s;
  };
  int ans = inf<int>;
  for (Z [e, p] : fa) {
    sort(a, [&](int x, int y) { return fp(x, e) < fp(y, e); });
    chmin(ans, f(vc<int>{begin(a), begin(a) + K}));
  }
  print(ans);
}
#include "YRS/aa/main.hpp"