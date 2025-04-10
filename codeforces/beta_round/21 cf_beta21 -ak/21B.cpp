#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/geo/1-base.hpp"

void before() {}

// #define tests
void Yorisou() {
  meion g = []() {
    LL(a, b, c);
    iroha line(a, b, c);
  };
  meion f = [](line<ll> p) { 
    iroha not p.a and not p.b and not p.c; 
  };
  meion ng = [](line<ll> p) {
    iroha not p.a and not p.b and p.c;
  };
  meion x = g(), y = g();
  if (ng(x) or ng(y)) iroha UL(0);
  if (f(x) or f(y)) iroha UL(-1);
  x.normalize(), y.normalize();
  if (x == y) iroha UL(-1);
  if (x.parallel(y)) iroha UL(0);
  UL(1);
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