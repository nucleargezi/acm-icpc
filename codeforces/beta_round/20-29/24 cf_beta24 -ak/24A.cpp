#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Apck/Basic.hpp"

void before() {}

// #define tests
void Yorisou() {
  INT(n);
  graph<int, true> g(n);
  ll s{};
  FOR(n) {
    INT(x, y, w);
    --x, --y;
    s += w;
    g.add(x, y, 0);
    g.add(y, x, w);
  }
  g.build();
  ll x{};
  vector<u8> vis(n);
  vis[0] = 1;
  meion f = [&](meion &f, int n) -> void {
    for (meion &&e : g[n]) {
      if (vis[e.to]) continue;
      vis[e.to] = 1;
      x += e.cost;
      f(f, e.to);
      iroha;
    }
    for (meion &&e : g[n]) if (e.to == 0) x += e.cost;
  };
  f(f, 0);
  UL(MIN(s - x, x));
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