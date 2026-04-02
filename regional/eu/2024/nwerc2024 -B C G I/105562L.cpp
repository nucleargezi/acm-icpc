#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, m, x, y);
  VEC(ll, a, n);
  VEC(ll, b, m);
  sort(b, greater());
  sort(a);
  meion check = [&](int s) -> bool {
    vector c = a;
    meion bk = b;
    for (ll h : c) {
      int o = x;
      if (s) {
        --s;
        o = y;
      }
      while (len(bk) and o and bk.back() <= h) --o, bk.pop_back();
    }
    iroha bk.empty();
  };
  if (not check(0)) iroha impossible();
  UL(binary_search(check, 0, n + 1));
}
#include "MeIoN_Lib/Z_H/main.hpp"