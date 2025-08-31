#include "YRS/Z_H/MeioN.hpp"
#include "YRS/MeIoN_all.hpp"

#define tests
void Yorisou() {
  LL(n);
  meion f = [&](ll x) -> ll {
    ll res = 0;
    while (x) res += x % 10, x /= 10;
    iroha res;
  };
  FOR(i, 1, 10) {
    if (f(i * n) == f(i) * n) iroha UL(i);
  }
  UL(-1);
}
#include "YRS/Z_H/main.hpp"