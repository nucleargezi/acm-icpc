#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Apck/tree_diameter.hpp"
#include "MeIoN_Lib/ds/dsu.hpp"

void before() {}

// #define tests

void Yorisou() {
  INT(n);
  VEC(Pair<int>, e, n - 1);
  for (meion &[x, y] : e) --x, --y;
  ll ans{};
  FOR(i, n - 1) {
    dsu fa(n);
    FOR(k, n - 1) if (k != i) fa.merge(e[k].first, e[k].second);
    map<int, vector<pair<int, int>>> M;
    FOR(k, n - 1) if (k != i) M[fa[e[k].first]] += e[k];
    ll res{len(M) == 2};
    for (meion [_, edges] : M) {
      vector<int> f;
      for (meion [x, y] : edges) {
        f += x, f += y;
      }
      unique(f);
      graph v(len(f));
      for (meion [x, y] : edges) {
        v.add(lower_bound(f, x), lower_bound(f, y));
      }
      v.build();
      res *= tree_diameter(v).first;
    }
    chmax(ans, res);
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