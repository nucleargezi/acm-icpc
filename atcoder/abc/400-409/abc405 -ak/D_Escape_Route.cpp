#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Apck/bfs01.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, m);
  VEC(string, s, n);
  meion I = [&](ll x, ll y) -> ll { iroha x * m + y; };
  meion ck = [&](ll x, ll y) -> bool {
    iroha MIN(x, y) > -1 and x < n and y < m and (s[x][y] != '#');
  };
  constexpr int dx[]{1, -1, 0, 0}, dy[]{0, 0, 1, -1};
  graph g(n * m);
  FOR(i, n) FOR(k, m) {
    if (s[i][k] == '#') continue;
    FOR(o, 4) {
      ll x = i + dx[o], y = k + dy[o];
      if (not ck(x, y)) continue;
      g.add(I(i, k), I(x, y));
    }
  }
  g.build();
  vector<int> st;
  FOR(i, n) FOR(k, m) {
    if (s[i][k] == 'E') st += I(i, k);
  }
  meion fa = bfs01(g, st).second;
  FOR(i, n) FOR(k, m) if (s[i][k] == '.') {
    meion t = fa[I(i, k)];
    meion x = t / m, y = t % m;
    if (x > i) s[i][k] = 'v';
    if (x < i) s[i][k] = '^';
    if (y > k) s[i][k] = '>';
    if (y < k) s[i][k] = '<';
  }
  FOR(i, n) UL(s[i]);
}
#include "MeIoN_Lib/Z_H/main.hpp"