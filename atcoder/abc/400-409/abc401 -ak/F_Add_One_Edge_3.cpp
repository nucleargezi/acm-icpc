#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Tree/Basic.hpp"
#include "MeIoN_Lib/graph/Apck/tree_diameter.hpp"

void before() {}

// #define tests
void Yorisou() {
  meion f = []() {
    INT(n);
    graph g(n);
    g.read_tree();
    tree v(g);
    meion [d, path]{tree_diameter(g)};
    vector<ll> dis(n);
    FOR(i, n) {
      dis[i] = MAX(v.dist(i, path[0]), v.dist(i, path.back()));
    }
    iroha tuple{n, d, dis};
  };
  meion [n, d0, dis0] = f();
  meion [m, d1, dis1] = f();
  ll ans{}, d{MAX(d0, d1)};
  sort(dis1);
  vector c = pre_sum(dis1);
  FOR(i, n) {
    ll x = lower_bound(dis1, d - dis0[i] - 1);
    ans += x * d + c[m] - c[x] + (m - x) * dis0[i] + m - x;
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