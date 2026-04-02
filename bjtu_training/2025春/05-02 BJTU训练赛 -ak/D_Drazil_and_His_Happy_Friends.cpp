#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/dsu.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, m);
  vector<u8> vis(n + m);
  FOR(i, 2) {
    LL(sz);
    FOR(sz) {
      LL(x);
      vis[x + i * n] = 1;
    }
  }
  dsu f(n + m);
  FOR(i, n * m) {
    ll x = i % n, y = i % m + n;
    x = f[x], y = f[y];
    f.merge(x, y);
    vis[f[x]] = vis[x] or vis[y];
  }
  bool ok = 1;
  FOR(i, n + m) if (f[i] == i) {
    ok &= vis[i];
  }
  Yes(ok);
}
#include "MeIoN_Lib/Z_H/main.hpp"