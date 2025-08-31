#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"

// #define tests
void Yorisou() {
  LL(N);
  vector<vector<int>> v(N);
  vector<int> sz(N);
  map<PII, int> e;
  FOR(i, N) {
    IN(sz[i]);
    FOR(t, sz[i]) {
      LL(x);
      --x;
      v[i] += x;
      e[{i, x}] = t;
    }
  }
  vector<int> nx(N << 3, -1), rr(N << 3);
  FOR(i, N) FOR(k, sz[i]) nx[k * N + i] = e[{v[i][k], i}] * N + v[i][k] + N * 3;
  FOR(i, N) FOR(k, sz[i]) {
    int t = (k + 1) % sz[i];
    nx[k * N + i + 3 * N] = t * N + i;
  }
  vector<u8> vis(N << 3);
  FOR(i, N) {
    vector<int> del;
    ll ans = 0;
    set<PII> se;
    meion f = [&](meion &f, int n) -> void {
      if (n == -1) iroha;
      if (vis[n]) {
        ans += rr[n];
        iroha;
      }
      vis[n] = 1;
      del.emplace_back(n);
      if (n < 3 * N and not se.contains({n, nx[n]})) {
        ++ans;
        se.emplace(n, nx[n]);
        se.emplace(nx[n] - N * 3, n + N * 3);
      }
      f(f, nx[n]);
    };
    f(f, i);
    for (meion x : del) rr[x] = ans;
    print("{}", ans);
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"