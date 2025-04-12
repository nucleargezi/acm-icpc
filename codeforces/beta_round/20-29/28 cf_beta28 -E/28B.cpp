#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/dsu.hpp"

void before() {}

// #define tests
void Yorisou() {
  INT(n);
  VEC(int, a, n);
  VEC(int, d, n);
  dsu f(n);
  FOR(i, n) {
    --a[i];
    if (i - d[i] > -1) f.merge(i, i - d[i]);
    if (i + d[i] < n) f.merge(i, i + d[i]);
  }
  FOR(i, n) if (f[i] != f[a[i]]) iroha NO();
  YES();
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