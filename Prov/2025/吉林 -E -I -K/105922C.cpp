#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

// #define tests
using mint = M99;
void Yorisou() {
  LL(n, K);
  VEC(mint, a, n);
  S(go);
  mint ans = 0;
  reverse(go);
  if (go[0] == 's') {
    ans = SUM<mint>(a);
  } else {
    ans = 1;
    FOR(i, n) ans *= a[i];
  }
  FOR(i, 1, K) {
    char op = go[i];
    if (op == 's') {
      ans *= n;
    } else {
      ans = ans.pow(n);
    }
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"