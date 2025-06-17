#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint_d.hpp"

// #define tests
using mint = dmint;
void Yorisou() {
  LL(n, m, k);
  VEC(T3<ll>, a, k);
  LL(mod);
  for (meion &[x, y, w] : a) --x, --y;
  if ((n ^ m) & 1) iroha UL(0);
  
  mint::set_mod(mod);
  if (n < m) {
    swap(n, m);
    for (meion &[x, y, w] : a) swap(x, y);
  }
  vector<int> c(n), s(n, 1);
  for (meion &[x, y, w] : a) {
    c[x] += 1;
    s[x] *= w;
  }
  mint ans = 1;
  bool f = 0;
  FOR(i, n) {
    if (c[i] == m and s[i] == 1) {
      ans = 0;
      break;
    }
    if (c[i] == m and s[i] == -1) continue;
    if (c[i] == 0 and not f) f = 1;
    else ans *= mint(2).pow(m - 1 - c[i]);
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"