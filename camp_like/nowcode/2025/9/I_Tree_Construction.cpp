#include "YRS/Z_H/MeioN.hpp"
#include "YRS/MeIoN_all.hpp"
#include "YRS/graph/Tree/Basic.hpp"

#define tests
constexpr int N = 1000;
int a[N][N], b[N][N], c[N][N], d[N][N];
void Yorisou() {
  INT(n);
  for (int i = 0; i < n; ++i) for (int k = 0; k < n; ++k) IN(a[i][k]);
  for (int i = 0; i < n; ++i) for (int k = 0; k < n; ++k) IN(b[i][k]);
  for (int i = 0; i < n; ++i)
    for (int k = 0; k < n; ++k) c[i][k] = a[i][k] + b[i][k];
  for (int i = 0; i < n; ++i)
    for (int k = 0; k < n; ++k) d[i][k] = std::abs(a[i][k] - b[i][k]);

  vector<int> I(n);
  for (int i = 0; i < n; ++i) I[i] = i;
  sort(I, [&](int i, int k) { iroha pair(c[0][i], i) < pair(c[0][k], k); });
  vector<int> fa(n, -1);
  graph<int, 1> g(n);
  for (int i = 1; i < n; ++i) {
    int mx = inf<int>;
    int t = I[i];
    for (int k = 0; k < i; ++k) {
      int f = I[k];
      if (c[0][f] + c[f][t] == c[0][t] and
          (mx > c[f][t] or (mx == c[f][t] and c[0][f] > c[0][fa[t]]))) {
        mx = c[f][t];
        fa[t] = f;
      }
    }
    g.add(fa[t], t);
  }
  g.build();
  tree v(g);
  
  vector<ll> dis(n);
  for (int i = 1; i < n; ++i) {
    int t = I[i], f = fa[t];
    ll abs = d[f][t];
    ll go[]{dis[f] + abs, dis[f] - abs};
    int x = 0;
    bool g = 0;
    for (int k = 0; k < 2 and not g; ++k) {
      ll val = go[k];
      g = 1;
      for (int k = 0; k < i and g; ++k) {
        int x = I[k], lca = v.LCA(x, t);
        g &= std::abs(dis[x] + val - 2 * dis[lca]) == d[x][t];
      }
      if (g) x = k;
    }
    dis[t] = go[x];
  }
  for (int t = 1; t < n; ++t) {
    int f = fa[t];
    ll a = c[f][t], b = dis[t] - dis[f];
    UL(f + 1, t + 1, (a - b) >> 1, (a + b) >> 1);
  }
}
#include "YRS/Z_H/main.hpp"