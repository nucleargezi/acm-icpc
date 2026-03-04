#define YRSD
// #include "YRS/aa/fast.hpp"
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
// #include "YRS/ds/basic/retsu.hpp"
// #include "YRS/mod/binom.hpp"
#include "YRS/ds/basic/bs.hpp"

void Yorisou() {
  INT(N);
  int M = 3 * N - 3;
  vc<bs> a(N);
  FOR(i, N) {
    STR(s);
    a[i] = bs(s);
  }
  vc<bs> bas, msk;
  FOR(i, N) {
    bs s(N);
    s.set(i);
    int sz = len(bas);
    FOR(k, sz) if (chmin(a[i], a[i] ^ bas[k])) s ^= msk[k];
    if (not a[i].any()) continue;
    FOR(k, sz) if (chmin(bas[k], bas[k] ^ a[i])) msk[k] ^= s;
    bas.ep(a[i]);
    msk.ep(s);
  }
  vc<int> ans;
  int sz = len(bas);
  FOR(i, sz) {
    bs t(M), s(N);
    FOR(k, i, sz) {
      t ^= bas[k];
      s ^= msk[k];
      ll c = t.count();
      if (M - N + 2 > c and c > N - 1) {
        FOR(i, N) if (s[i]) ans.ep(i + 1);
        print(len(ans));
        print(ans);
        return;
      }
    }
  }
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"