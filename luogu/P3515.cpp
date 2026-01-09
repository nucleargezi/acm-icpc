#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/dp/monoton.hpp"

#define tests 0
#define fl 0
#define DB 10
using re = double;
void Yorisou() {
  INT(N);
  VEC(int, a, N);
  vc<re> s(N);
  FOR(i, 1, N) s[i] = sqrtl(i);
  Z w = [&](int l, int r) { return a[l] - a[r] + s[r - l]; };
  vc<re> f = monoton_dp_max<re>(N, 1, w);
  reverse(all(a));
  vc<re> g = monoton_dp_max<re>(N, 1, w);
  reverse(all(g));
  FOR(i, N) print((int)std::ceil(max(g[i], f[i])));
}
#include "YRS/aa/main.hpp"