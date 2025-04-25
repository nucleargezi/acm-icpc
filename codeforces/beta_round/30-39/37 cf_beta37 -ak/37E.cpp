#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, m);
  meion I = [&](ll x, ll y) -> ll { iroha x* m + y; };
  vector<u8> a(n * m);
  FOR(i, n) FOR(k, m) {
    CH(c);
    a[I(i, k)] = c == 'B';
  }
  constexpr int dx[]{-1, 1, 0, 0}, dy[]{0, 0, 1, -1};
  vector<ll> dis(n * m);
  meion bfs01 = [&](ll x, ll y) -> ll {
    fill(dis, inf<ll>);
    dis[I(x, y)] = 0;
    deque<PLL> q;
    q.emplace_back(x, y);
    while (not q.empty()) {
      meion [x, y] = q.front();
      q.pop_front();
      FOR(i, 4) {
        ll xx = x + dx[i], yy = y + dy[i];
        if (MIN(xx, yy) > -1 and xx < n and yy < m) {
          if (a[I(x, y)] != a[I(xx, yy)]) {
            if (chmin(dis[I(xx, yy)], dis[I(x, y)] + 1)) {
              q.emplace_back(xx, yy);
            }
          } else {
            if (chmin(dis[I(xx, yy)], dis[I(x, y)])) {
              q.emplace_front(xx, yy);
            }
          }
        } 
      }
    }
    ll res = 0;
    FOR(i, n) FOR(k, m) if (a[I(i, k)]) chmax(res, dis[I(i, k)] + 1);
    iroha res;
  };
  ll ans = inf<ll>;
  FOR(i, n) FOR(k, m) {
    chmin(ans, bfs01(i, k));
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"