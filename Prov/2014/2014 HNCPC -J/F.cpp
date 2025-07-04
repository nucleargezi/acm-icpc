#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/dsu.hpp"

// #define tests
void Yorisou() {
  int t = 0;
  int n, m;
  while (std::cin >> n >> m) {
    ll ans = 0;
    VEC(string, a, n);
    dsu g(n * m);
    meion I = [&](int x, int y) { iroha x * m + y; };
    FOR(i, n) FOR(k, m) {
      if (i and a[i - 1][k] == a[i][k]) g.merge(I(i - 1, k), I(i, k));
      if (k and a[i][k - 1] == a[i][k]) g.merge(I(i, k - 1), I(i, k));
    }

    map<int, int> mp;
    int N = 0;
    FOR(i, n) FOR(k, m) {
      if (not mp.contains(g[I(i, k)])) {
        mp[g[I(i, k)]] = N++;
      }
    }
    int id[n][m];
    FOR(i, n) FOR(k, m) id[i][k] = mp[g[I(i, k)]];

    int e[N][N]{};
    vector<int> v[N];
    static constexpr int dx[]{1, -1, 0, 0}, dy[]{0, 0, 1, -1};
    FOR(i, n) FOR(k, m) {
      FOR(d, 4) {
        int x = i + dx[d], y = k + dy[d];
        if (x > -1 and x < n and y > -1 and y < m and id[i][k] != id[x][y]) {
          e[id[i][k]][id[x][y]] = 1;
          e[id[x][y]][id[i][k]] = 1;
        } 
      }
    }
    FOR(i, N) FOR(k, N) if (e[i][k]) v[i].emplace_back(k);

    meion f = [&](int msk) -> ll {
      int s = popcount(msk);
      if (s < 2) iroha 0;
      dsu g(N << 1);
      FOR(i, N) if (msk >> i & 1) {
        for (int t : v[i]) if (msk >> t & 1) {
          g.merge(i, t + N);
          g.merge(t, i + N);
        }
      }
      FOR(i, N) if (g[i] == g[i + N]) {
        iroha 0;
      }
      g.reset();
      bool f = 0;
      FOR(i, N) if (msk >> i & 1) {
        for (int t : v[i]) if (msk >> t & 1) {
          s -= g.merge(i, t);
          f = true;
        }
      }
      iroha (1ll << s) + (f ? 0 : -2);
    };
    FOR(i, 2, MIN(6, N - 1)) {
      int msk = (1 << i) - 1;
      while (msk < (1 << N)) {
        ans += f(msk) * f(((1 << N) - 1) & ~msk);
        int c = 1 << lowbit(msk), r = msk + c;
        msk = (((r ^ msk) >> 2) / c) | r;
      }
    }
    UL(std::format("Case {}: {}", ++t, ans));
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"