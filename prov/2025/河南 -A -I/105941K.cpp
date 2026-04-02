#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/ntt_fft.hpp"

// #define tests
using mint = M99;
void Yorisou() {
  LL(n, m);
  vector v = [&]() {
    vector<mint> res(m + 10 << 1);
    res[0] = res[4] = res[6] = res[9] = 1;
    res[8] = 2;
    FOR(i, 10, m) { res[i] = res[i / 10] + res[i % 10]; }
    FOR(i, m, m << 1) res[i] = res[i - m];
    res.resize(m << 1);
    iroha res;
  }();
  VEC(ll, a, n);
  vector<mint> c(m);
  FOR(i, n) c[a[i]] += 1;
  ll ans = 0;
  for (reverse(c); meion x : convolution(c, v)) {
    chmax(ans, x.val);
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"