#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N);
  VEC(string, a, N);
  vc<PII> cp;
  vc<int> c(N);
  FOR(i, N) FOR(k, i + 1, N) {
    if (a[i][k] == '-') cp.ep(i, k);
    else ++c[a[i][k] == 'x' ? i : k];
  }
  int n = len(cp), ans = N;
  FOR(s, 1 << n) {
    FOR(i, n) ++c[s >> i & 1 ? cp[i].fi : cp[i].se];
    vc<int> f = c;
    unique(f);
    FOR(i, len(f)) if (c[0] == f[i]) chmin(ans, i + 1);
    FOR(i, n) --c[s >> i & 1 ? cp[i].fi : cp[i].se];
  }
  print(ans);
}
#include "YRS/aa/main.hpp"