#define YRSD
// #include "YRS/aa/fast.hpp"
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ds/basic/retsu.hpp"
// #include "YRS/mod/mint.hpp"
// #include "YRS/aa/def.hpp"

using re = double;
void Yorisou() {
  INT(N);
  REAL(pa, pb);
  VEC(int, a, N);
  VEC(int, b, N);
  sort(a);
  sort(b);

  Z sing = [&](vc<int> a, re p) {
    vc<re> f(1 << N);
    retsu<re> g(N, N);
    f[0] = 1;
    FOR(s, (1 << N) - 1) {
      int t = lowbit(~s);
      if (pc(s) == N - 1) {
        g[pc(s)][t] += f[s];
      } else {
        re tp = f[s] * p;
        g[pc(s)][t] += tp;
        f[1 << t | s] += tp;
        int sz = N - pc(s) - 1;
        tp = (1 - p) / sz * f[s];
        FOR(i, N) if ((s >> i & 1) == 0 and i != t) {
          g[pc(s)][i] += tp;
          f[1 << i | s] += tp;
        }
      }
    }
    return g;
  };

  retsu<re> f = sing(a, pa), g = sing(b, pb);
  re s = 0;
  FOR(i, N) FOR(k, N) FOR(j, N) if (a[k] > b[j]) {
    s += f[i][k] * g[i][j] * (a[k] + b[j]);
  }
  setp(10);
  print(s);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"