#define YRSD
#include "YRS/aa/fast.hpp"
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ds/basic/retsu.hpp"
// #include "YRS/mod/mint.hpp"
// #include "YRS/aa/def.hpp"

using re = double;
void Yorisou() {
  INT(N, L);
  L *= 60;
  vc<int> a(N);
  FOR(i, N) {
    STR(t);
    int m = stoi(t.substr(0, 2)), s = stoi(t.substr(3));
    a[i] = m * 60 + s;
  }
  int al = SUM(a);
  if (al <= L) return print(N);

  retsu<ll> w(N + 1, L);
  w[0][0] = 1;
  FOR(j, N) FOR_R(i, j + 1) FOR_R(k, a[j], L) {
    w[i + 1][k] += w[i][k - a[j]];
  }

  vc<re> fac(N + 1), ifac(N + 1), c(N);
  fac[0] = ifac[0] = 1;
  FOR(i, N) fac[i + 1] = fac[i] * (i + 1);
  FOR(i, N) ifac[i + 1] = ifac[i] / (i + 1);
  FOR(i, N) c[i] = fac[i] * ifac[N] * fac[N - i - 1];

  re s = 0;
  FOR(i, N) {
    int g = a[i];
    FOR(i, N) FOR(k, g, L) w[i + 1][k] -= w[i][k - g];
    FOR(i, N) FOR(k, L) s += w[i][k] * c[i];
    FOR_R(i, N) FOR_R(k, g, L) w[i + 1][k] += w[i][k - g];
  }
  setp(10);
  print(s);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"