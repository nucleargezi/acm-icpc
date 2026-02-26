#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/g/Basic.hpp"
#include "YRS/ds/basic/queue.hpp"
#include "YRS/ds/basic/retsu.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N, M, K);
  graph g(N);
  g.read_graph(M);
  ll msk = 1;
  retsu<u8> dp(1 << (K + 1), N, inf<u8>);
  FOR_R(i, 1, N) {
    vc<char> s, id(N, -1);
    if (pc(msk) == K + 1) continue;
    msk |= 1ll << i;
    FOR(i, N) if (msk >> i & 1) s.ep(i);
    int sz = len(s);
    FOR(i, sz) id[s[i]] = i;
    
    dp.fill(inf<u8>);
    queue<tuple<u8, int, u8>> q((1 << sz) * N);
    q.eb(0, 1, 0);
    dp[1][0] = 0;
    while (not q.empty()) {
      Z [d, s, n] = pop(q);
      if (d != dp[s][n] or d >= K) continue;
      for (Z &&e : g[n]) {
        if (id[e.to] != -1) {
          int t = 1 << id[e.to] | s;
          if (chmin(dp[t][e.to], d + 1)) q.eb(d + 1, t, e.to);
        } else {
          if (chmin(dp[s][e.to], d + 1)) q.eb(d + 1, s, e.to);
        }
      }
    }
    bool ok = 0;
    FOR(i, N) if (dp[(1 << sz) - 1][i] <= K) ok = 1;
    if (ok == 0) msk ^= 1ll << i;
  }
  ll s = 0;
  FOR(i, N) if (msk >> i & 1) s += (1ll << i) - 1;
  print(s);
}
#include "YRS/aa/main.hpp"