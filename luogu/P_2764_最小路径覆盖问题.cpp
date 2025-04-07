#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/dsu.hpp"
#include "MeIoN_Lib/flow/max_flow.hpp"

void before() {}

// #define tests
#define fuck UL("NMSL"), exit(0)
NAME MeIoN_is_UMP45() {
  INT(n, m);
  int s {}, t {n << 1 | 1};
  max_flow<int> FL(t + 1, s, t);
  FOR(i, 1, n + 1) {
    FL.add(s, i, 1);
    FL.add(i + n, t, 1);
  }
  FOR(m) {
    INT(x, y);
    FL.add(x, y + n, 1);
  }
  FL.flow();
  dsu g(n);
  for (meion[f, to, flow] : FL.get_flow_edges()) {
    if (f == s or to == t) continue;
    if (f > n) f -= n;
    if (to > n) to -= n;
    g.merge(--f, --to);
  }
  vector ans = g.get_group();
  for (meion v : ans) {
    for (int &x : v) ++x;
    UL(v);
  }
  UL(len(ans));
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
  MeIoN_is_UMP45();
  iroha 0;
}