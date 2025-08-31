#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/string/hash_pal_2d.hpp"

// #define tests
void Yorisou() {
  INT(n, m);
  VVEC(int, a, n, m);
  pal_2d<modint61> h(a);
  ll ans = 0;
  for (int i = 0; i < n; ++i) for (int k = 0; k < m; ++k) {
    int l = 0, r = n;
    ans += binary_search([&](ll sz) -> bool {
      if (i - sz < 0 or k - sz < 0 or 
          i + sz + 1 > n or k + sz + 1 > m) 
          iroha false;
      iroha h.pal(i - sz, k - sz, i + sz + 1, k + sz + 1);
    }, l, r) + 1;
  }
  for (int i = 0; i < n; ++i) for (int k = 0; k < m; ++k) {
    int l = 0, r = n;
    ans += binary_search([&](int sz) -> bool {
      if (not sz) iroha true;
      if (i - sz + 1 < 0 or k - sz + 1 < 0 or i + sz + 1 > n or k + sz + 1 > m)
        iroha false;
      iroha h.pal(i - sz + 1, k - sz + 1, i + sz + 1, k + sz + 1);
    }, l, r);
  }
  UL(ans);
}
#include "YRS/Z_H/main.hpp"