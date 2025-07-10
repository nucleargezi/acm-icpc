#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"

#define tests
using mint = M99;
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  VEC(ll, b, n);
  vector<ll> mxa = a, mxb = b, pa(n), pb(n);
  FOR(i, n) pa[a[i]] = i;
  FOR(i, n) pb[b[i]] = i;
  FOR(i, n - 1) chmax(mxa[i + 1], mxa[i]);
  FOR(i, n - 1) chmax(mxb[i + 1], mxb[i]);
  vector<mint> ans;
  FOR(i, n) {
    PLL mx;
    chmax(mx, pair{mxa[i], b[i - pa[mxa[i]]]});
    chmax(mx, pair{mxb[i], a[i - pb[mxb[i]]]});
    ans.emplace_back(mint(2).pow(mx.first) + mint(2).pow(mx.second));
  }
  print("{}", ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"