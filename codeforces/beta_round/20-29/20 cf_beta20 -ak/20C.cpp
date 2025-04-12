#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Apck/dijkstra.hpp"

void before() {}

// #define tests
void Yorisou() {
  INT(n, m);
  graph<ll> g(n);
  g.read_graph<true>(m);
  meion [dis, fa] = dijkstra(g, 0);
  if (dis[n - 1] == inf<ll>) iroha UL(-1);
  vector<int> ans{n--};
  while (fa[n] != -1) {
    ans += fa[n] + 1;
    n =fa[n];
  }
  reverse(ans);
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