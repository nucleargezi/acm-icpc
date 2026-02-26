#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 1
#define fl 0
#define DB 10
void Yorisou() {
  INT(N, K);
  VEC(PII, e, K);
  INT(sz);
  VEC(int, a, sz);
  FOR(i, K) --e[i].fi, --e[i].se;
  vc<u8> kl(N), ans(K), vis(N);
  FOR(i, sz) kl[a[i] - 1] = 1;
  FOR(i, N) vis[i] = not kl[i];
  FOR_R(i, K) {
    Z [f, t] = e[i];
    if (kl[t] and vis[f]) kl[t] = 0, vis[f] = 1, vis[t] = 1, ans[i] = 1;
  }
  if (SUM<int>(kl)) return NIE();
  TAK();
  string s;
  FOR(i, K) s += ans[i] ? 'T' : 'N';
  print(s);
}
#include "YRS/aa/main.hpp" 