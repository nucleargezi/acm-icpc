#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Apck/scc.hpp"
#include "MeIoN_Lib/ds/dsu.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, m);
  graph<bool, true> g(n);
  dsu f(n);
  FOR(m) {
    LL(x, y);
    g.add(--x, --y);
    f.merge(x, y);
  }
  g.build();
  meion [N, id] = scc(g);
  meion sccs = get_scc_group(N, id);
  vector<u8> vis(n);
  for (meion &v : sccs) {
    if (len(v) > 1) {
      vis[f[v[0]]] = 1;
    }
  }
  ll ans{};
  FOR(i, n) if (i == f[i]) {
    ans += f.size(i) - not vis[i];
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