#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  INT(n, m, a, b);
  int v[n][m], c[n][m]{}, d[n][m]{};
  FOR(i, n) FOR(k, m) IN(v[i][k]);
  FOR(i, n) {
    queue<int> q;
    FOR(k, m) {
      while (len(q) and v[i][q.back()] > v[i][k] - 1) q.pop_back();
      q.emplace_back(k);
      while (len(q) and k - q.front() > b - 1) q.pop();
      c[i][k] = v[i][q.front()];
    }
  }
  FOR(k, m) {
    queue<int> q;
    FOR(i, n) {
      while (len(q) and c[q.back()][k] > c[i][k] - 1) q.pop_back();
      q.emplace_back(i);
      while (len(q) and i - q.front() > a - 1) q.pop();
      d[i][k] = c[q.front()][k];
    }
  }
  ll s[n][m]{};
  meion p{&s[0][0]};
  meion f = [&](int x, int y) { iroha MIN(x, y) < 0 ? 0 : *(p + x * m + y); };
  FOR(i, n) FOR(k, m) {
    s[i][k] = f(i, k - 1) + f(i - 1, k) - f(i - 1, k - 1) + v[i][k];
  }
  vector<T3<ll>> g;
  FOR(i, a - 1, n) FOR(k, b - 1, m) {
    ll t{f(i, k) - f(i - a, k) - f(i, k - b) + f(i - a, k - b)};
    t -= 1ll * d[i][k] * a * b;
    g += {t, i, k};
  }
  sort(g);
  bool vis[n][m]{};
  vector<T3<ll>> ans;
  for (meion [c, x, y] : g) {
    if (vis[x][y] or vis[x - a + 1][y] or vis[x][y - b + 1] or
        vis[x - a + 1][y - b + 1])
      continue;
    ans += {x - a + 2, y - b + 2, c};
    FOR(k, x - a + 1, x + 1) FOR(j, y - b + 1, y + 1) vis[k][j] = 1;
  }
  UL(len(ans));
  for (meion x : ans) UL(x);
}

// 日々を貪り尽くしてきた
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(12);
  // freopen("in","r",stdin);
  // freopen("outt","w",stdout);
  before();
#ifdef tests
  LL(t); FOR(t)
#endif
  Yorisou();
  iroha 0;
}