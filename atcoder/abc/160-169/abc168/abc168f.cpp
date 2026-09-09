#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/basic/retsu.hpp"

void Yorisou() {
  INT(N, M);
  VEC(T3<int>, a, N);
  VEC(T3<int>, b, M);
  vc<int> f{0}, g{0};
  for (var [l, r, y] : a) f.ep(l), f.ep(r), g.ep(y);
  for (var [x, l, r] : b) f.ep(x), g.ep(l), g.ep(r);
  unique(f), unique(g);

  int n = si(f) * 2 - 1, m = si(g) * 2 - 1;
  retsu<char> mp(n, m);
  for (Z [l, r, y] : a) {
    l = lb(f, l) << 1, r = lb(f, r) << 1, y = lb(g, y) << 1;
    FOR(i, l, r + 1) mp[i][y] = -1;
  }
  for (Z [x, l, r] : b) {
    x = lb(f, x) << 1, l = lb(g, l) << 1, r = lb(g, r) << 1;
    FOR(i, l, r + 1) mp[x][i] = -1;
  }

  constexpr int dx[]{1, -1, 0, 0}, dy[]{0, 0, 1, -1};
  int x = lb(f, 0) << 1, y = lb(g, 0) << 1;
  mp[x][y] = 1;
  vc<PII> q{{x, y}};
  FOR(i, si(q)) {
    Z [x, y] = q[i];
    if (x == 0 or y == 0 or x == n - 1 or y == m - 1) return print("INF");
    FOR(d, 4) {
      int xx = x + dx[d], yy = y + dy[d];
      if (xx < 0 or xx >= n or yy < 0 or yy >= m or mp[xx][yy]) continue;
      mp[xx][yy] = 1;
      q.ep(xx, yy);
    }
  }

  ll s = 0;
  FOR(i, 1, n, 2) FOR(k, 1, m, 2) if (mp[i][k] == 1) {
    s += ll(f[i / 2 + 1] - f[i / 2]) * (g[k / 2 + 1] - g[k / 2]);
  }
  print(s);
}

int main() { Yorisou(); }