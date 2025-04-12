#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/geo/7-points_in_triangles.hpp"

void before() {}

// #define tests
using P = point<ll>;
void Yorisou() {
  INT(n, m);
  VEC(P, a, n);
  VEC(P, b, m);
  count_points_in_triangles g(a, b);
  ll ans{};
  FOR(i, n) FOR(k, i) FOR(j, k) ans += not g.count3(i, k, j);
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