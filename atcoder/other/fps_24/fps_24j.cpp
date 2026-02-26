#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/po/all.hpp"
#include "YRS/po/online_conv.hpp"

#define tests 0
#define fl 0
#define DB 10
using mint = M99;
using fps = vc<mint>;
void Yorisou() {
  INT(N, M, L);
  vc<int> a(N + 1);
  FOR(M) {
    INT(x);
    a[x] = 1;
  }
  vc<u8> vis(N + 1);
  FOR(L) {
    INT(x);
    vis[x] = 1;
  }
  online_conv<mint> g;
  fps f(N + 1);
  mint im = mint(M).inv();
  f[0] = 1;
  FOR(i, N) {
    f[i + 1] = g(f[i], a[i + 1]) * im;
    if (vis[i + 1]) f[i + 1] = 0;
  }
  mint s = 0;
  FOR_R(i, N) a[i] += a[i + 1];
  FOR(i, N) s += f[i] * a[N - i] * im;
  print(s);
}
#include "YRS/aa/main.hpp"