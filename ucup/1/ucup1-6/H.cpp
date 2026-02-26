#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ge/exp/minimum_enclosing_circle.hpp"
#include "YRS/ge/ds/dynamic_hull.hpp"
#include "YRS/ds/basic/retsu.hpp"

#define tests 0
#define fl 0
#define DB 10
using re = ld;
using P = point<re>;
void Yorisou() {
  LL(N, K, X);
  vc<P> a(N);
  FOR(i, N) {
    a[i].x = X;
    X = X * 233811181 + 1;
    X %= (1ll << 31) - 1;
    a[i].y = X;
    X = X * 233811181 + 1;
    X %= (1ll << 31) - 1;
  }
  
  retsu<re> w(N, N + 1);
  FOR(i, N) {
    vc<P> p;
    dynamic_hull<re> hull;
    FOR(k, i, N) {
      if (k - i + 1 > 3 and hull.side(a[k]) != -1) {
        w[i][k + 1] = w[i][k];
      } else {
        p.ep(a[k]);
        hull.add(a[k]);
        Z [C, a, b, c] = minimum_enclosing_circle(p);
        w[i][k + 1] = C.R;
      }
    }
  }
  
  constexpr re eps = 1e-9l;
  retsu<int> R(N, N + 1);
  FOR(l, N) FOR_R(r, l + 1, N + 1) {
    if (r == N) R[l][r] = N;
    else {
      if (w[l][r] < w[l][r + 1] - eps) R[l][r] = r;
      else R[l][r] = R[l][r + 1];
    }
  }
  vc<re> f(N + 1, inf<re>);
  f[0] = 0;
  FOR(K) {
    FOR_R(l, N) if (f[l] != inf<re>) {
      for (int r = l + 1; r < N + 1; r = R[l][r] + 1) {
        chmin(f[R[l][r]], f[l] + w[l][R[l][r]]);
      }
    }
    FOR_R(i, N) chmin(f[i], f[i + 1]);
  }
  setp(10);
  print(f[N]);
}
#include "YRS/aa/main.hpp"