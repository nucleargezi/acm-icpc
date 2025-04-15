#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/dsu.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, m);
  vector<vector<PLL>> v(n);
  dsu g(n);
  FOR(m) {
    LL(x, y, w);
    g.merge(--x, --y);
    v[x] += PLL{y, w};
    v[y] += PLL{x, w};
  }
  vector<ll> ans(n);
  meion gps = g.get_group();
  FOR(bit, 30) {
    vector<ll> col(n);
    for (meion &g : gps) {
      ll mx{inf<ll>};
      FOR(c, 2) {
        for (ll x : g) col[x] = -1;
        col[g[0]] = c;
        int ok{1};
        meion f = [&](meion &f, ll n, ll fa) -> void {
          for (meion [x, w] : v[n]) {
            if (x == fa) continue;
            int t{w >> bit & 1 ^ col[n]};
            if (col[x] == -1) {
              col[x] = t;
              f(f, x, n);
            } else if (col[x] != t) {
              ok = 0;
            }
          }
        };
        f(f, g[0], -1);
        if (ok) {
          ll s{};
          for (ll x : g) s += col[x];
          if (chmin(mx, s)) {
            for (ll x : g) {
              ans[x] &= ~(1 << bit);
              ans[x] |= (1 << bit) * col[x];
            }
          }
        } else {
          iroha UL(-1);
        }
      }
    }
  }
  UL(ans);
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