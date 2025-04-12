#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Apck/Basic.hpp"

void before() {}

// #define tests
void Yorisou() {
  INT(n, m);
  graph g(n);
  g.read_graph(m);
  vector<int> dis(n);
  vector<u8> vis(n);
  vector<int> O(n), E(n), E_e(m), O_e(m);
  int s{};
  meion f = [&](meion &f, int n, int fa, int fo) -> void {
    vis[n] = 1;
    for (meion[_, x, __, id] : g[n]) if (x != fa) {
      if (vis[x]) {
        if (dis[x] < dis[n]) {
          if ((dis[x] ^ dis[n]) & 1) {
            ++E[n], --E[x];
            E_e[id] = 1;
          } else {
            ++s;
            ++O[n], --O[x];
            O_e[id] = 1;
          }
        }
      } else {
        dis[x] = dis[n] + 1;
        f(f, x, n, id);
        O[n] += O[x], E[n] += E[x];
      }
    }
    if (fo != -1) O_e[fo] = O[n], E_e[fo] = E[n];
  };
  FOR(i, n) if (not vis[i]) f(f, i, i, -1);
  vector<ll> ans;
  FOR(i, m) if ((O_e[i] == s and not E_e[i]) or not s) ans += i + 1;
  UL(len(ans));
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