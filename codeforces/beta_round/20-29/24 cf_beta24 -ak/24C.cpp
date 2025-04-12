#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/geo/1-base.hpp"

void before() {}

// #define tests
using P = point<ll>;
void Yorisou() {
  LL(n, x);
  x %= n + n;
  PO(m);
  VEC(P, a, n);
  a += a;
  FOR(i, x) {
    m += (a[i] - m) * 2;
  }
  UL(m);
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