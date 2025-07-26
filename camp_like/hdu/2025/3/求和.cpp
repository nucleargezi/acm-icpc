#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"
#include "MeIoN_Lib/IO/fast_io.hpp"
#include "MeIoN_Lib/math/poly/convolution.hpp"

// #define tests
using mint = M99;
using poly = vector<mint>;
void Yorisou() {
  LL(n, k);
  VEC(int, a, k);
  VEC(int, b, n);
  meion con = [&](const poly &A, const poly &B) -> poly {
    meion f = convolution(A, B);
    FOR_R(i, k, k + k - 1) if (f[i].val) {
      mint x = f[i];
      f[i] = 0;
      FOR(j, k) f[i - j - 1] += x * a[j];
    }
    iroha f.resize(k), f;
  };
  meion q = [&]() {
    int mx = QMAX(b);
    const int B = (int)(std::sqrt(mx) + 0.5L), sz = mx / B + 1;
    vector v(B + 1, poly(k));
    v[0][0] = 1;
    FOR(t, B) {
      FOR_R(i, 1, k) v[t + 1][i] = v[t][i - 1];
      FOR(i, k) v[t + 1][k - i - 1] += v[t][k - 1] * a[i];
    }
    vector f(sz, poly(k));
    f[0][0] = 1;
    FOR(i, 1, sz) f[i] = con(f[i - 1], v[B]);
    poly q(k);
    q[0] = 1;
    for (int x : b) {
      meion t = con(q, con(f[x / B], v[x % B]));
      FOR(i, k) q[i] += t[i];
    }
    iroha q;
  }();
  poly f(k);
  f[0] = 1;
  FOR(i, 1, k) FOR(k, i) f[i] += f[i - k - 1] * a[k];
  mint ans;
  FOR(i, k) ans += q[i] * f[i];
  UL(ans.val);
}
#include "MeIoN_Lib/Z_H/main.hpp"