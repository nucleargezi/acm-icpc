#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/flow/max_flow.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
  INT(n, m);
  meion id = [&](int x, int y) -> int { iroha --x * m + y; };
  int s{}, t{n * m};
  max_flow FL(t + 1, s, t);
  FOR(i, 1, n + 1) FOR(k, 1, m) {
    INT(x);
    FL.add(id(i, k), id(i, k + 1), x, x);
  }
  FOR(i, 1, n) FOR(k, 1, m + 1) {
    INT(x);
    FL.add(id(i, k), id(i + 1, k), x, x);
  }
  FOR(i, 1, n) FOR(k, 1, m) {
    INT(x);
    FL.add(id(i, k), id(i + 1, k + 1), x, x);
  }
  FL.add(s, 1, inf<int>);
  UL(FL.flow());
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