#define YRSD
// #include "YRS/aa/fast.hpp"
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
// #include "YRS/ds/basic/retsu.hpp"
// #include "YRS/mod/mint.hpp"
// #include "YRS/aa/def.hpp"
#include "YRS/ds/un/dsu.hpp"

inline ll sq(ll x) { return x * x; }

ll dist(PLL a, PLL b) { return sq(a.fi - b.fi) + sq(a.se - b.se); }

void Yorisou() {
  INT(N);
  VEC(PLL, a, N);
  vc<tuple<ll, int, int>> es;
  FOR(i, N) FOR(k, i + 1, N) es.ep(dist(a[i], a[k]), i, k);
  sort(es);
  print(bina([&](ll L) -> bool {
    dsu g(N);
    for (Z [d, x, y] : es) {
      if (d > L * L * 100) break;
      g.merge(x, y);
    }
    return g[0] == g[N - 1];
  }, inf<int> / 10, 0) * 10);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"