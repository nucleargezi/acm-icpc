#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/flow/max_flow_min_cost.hpp"

void before() {}

// #define tests
constexpr int N = 2000;
ll a[N][N];
int I[N][N];
void Yorisou() {
  LL(n, m);
  ll sm = 0;
  FOR(i, n) FOR(k, m) {
    IN(a[i][k]);
    sm += a[i][k];
  }
  int s = 0, t = n * m + 1;
  mcf_graph<ll, ll, 1> FL(t + 1);
  int tt = 0;
  FOR(i, n) FOR(k, m) {
    if (not (i + k & 1)) {
      I[i][k] = ++tt;
    }
  }
  FOR(i, n) FOR(k, m) {
    if (i + k & 1) {
      I[i][k] = ++tt;
    }
  }
  constexpr int dx[]{1, -1, 0, 0}, dy[]{0, 0, 1, -1};
  FOR(i, n) FOR(k, m) {
    if ((i + k) & 1) {
      FL.add(I[i][k], t, 1, 0);
    } else {
      FL.add(s, I[i][k], 1, 0);
      FOR(d, 4) {
        int x = i + dx[d], y = k + dy[d];
        if (MIN(x, y) > -1 and x < n and y < m) {
          ll w = a[i][k] + a[x][y];
          if (w < 0) {
            FL.add(I[i][k], I[x][y], 1, w);
          }
        }
      }
    }
  }
  ll ans = -inf<ll>;
  for (meion x : FL.slope(s, t)) {
    chmax(ans, sm - x.second);
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"