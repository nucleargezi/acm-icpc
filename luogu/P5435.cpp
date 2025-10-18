#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/PR/gcd_fast.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

void before() {}

// #define tests
using mint = M99;
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  VEC(ll, b, n);
  vector<mint> ans(n);
  FOR(i, n) {
    mint d = i + 1;
    FOR(k, n) { 
      ans[i] += d * gcd_fast(a[i], b[k]); 
      d *= i + 1;
    }
  }
  FOR(i, n) UL(ans[i]);
}
#include "MeIoN_Lib/Z_H/main.hpp"