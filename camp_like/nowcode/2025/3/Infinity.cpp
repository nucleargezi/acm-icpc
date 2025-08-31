#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
// #include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/math/poly/convolution.hpp"
#include "MeIoN_Lib/math/poly/fps_log.hpp"
#include "MeIoN_Lib/math/poly/fps_exp.hpp"

// #define tests
using mint = M99;
constexpr int mod = 998244353;
void Yorisou() {
  LL(t, K);
  VEC(int, q, t);
  const int N = QMAX(q) + 1;
  int kk = (K + 1) % (mod - 1);
  vector<mint> facp(N, 1), invfacp(N, 1);
  FOR(i, 1, N) {
    facp[i] = fact<mint>(i).pow(kk);
    invfacp[i] = facp[i].inv();
  }
  vector<mint> f(N);
  FOR(i, 1, N) {
    const int M = N / i + 1;
    vector<mint> b(M);
    b[0] = 1;
    mint in = mint(i).pow(kk).inv(), mu = 1;
    for (int k = 1; k < M; ++k) {
      mu *= in;
      b[k] = mu * invfacp[k];
    }
    meion t = fps_log(b);
    for (int k = 1; k < M; ++k) {
      f[i * k] += t[k];
    }
  }
  meion v = fps_exp(f);
  for (int x : q) {
    UL(fact<mint>(x).pow(kk) * v[x]);
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"