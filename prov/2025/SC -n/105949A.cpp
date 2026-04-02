#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/Z_H/fast_io.hpp"

#define tests
void Yorisou() {
  LL(n, m);
  VEC(T4<int>, e, m);
  for (meion &[x, y, a, b] : e) --x, --y;
  const int N = n * 200 + 1;
  vector dis(n, vector<int>(N, inf<int> / 2));
  dis[0][0] = 0;
  FOR(i, 200 * n) {
    for (meion [f, t, a, b] : e) {
      if (i + a < N) {
        chmin(dis[t][i + a], dis[f][i] + b);
      }
    }
  }
  ll mx = inf<ll>, a, b;
  FOR(i, N) if (dis[n - 1][i] != inf<int> / 2) {
    if (chmin(mx, 1ll * dis[n - 1][i] * i)) {
      a = i, b = dis[n - 1][i];
    }
  }
  UL(a, b);
}
#include "MeIoN_Lib/Z_H/main.hpp"