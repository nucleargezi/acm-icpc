#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
using RE = long double;
constexpr int N = 8;
void Yorisou() {
  vector<ll> a(N), b(N);
  FOR(i, N) IN(a[i], b[i]);
  vector<int> I(N);
  iota(all(I), 0);
  int g[N >> 1], gg[N >> 2];
  Z cp = [&](int x, int y) -> RE {
    RE s = I[x] < I[y] ? a[x] : b[x];
    RE t = I[y] < I[x] ? a[y] : b[y];
    return s / (s + t);
  };
  RE s = 0;
  while (std::next_permutation(all(I))) {
    vector<int> ii = argsort(I);
    RE ss = 0;
    FOR(s, 1 << 4) {
      RE p = 1;
      FOR(i, 4) {
        if (s >> i & 1) p *= cp(ii[i << 1], ii[i << 1 | 1]), g[i] = ii[i << 1];
        else p *= cp(ii[i << 1 | 1], ii[i << 1]), g[i] = ii[i << 1 | 1];
      }
      FOR(s, 1 << 2) {
        RE pp = p;
        FOR(i, 2) {
          if (s >> i & 1) pp *= cp(g[i << 1], g[i << 1 | 1]), gg[i] = g[i << 1];
          else pp *= cp(g[i << 1 | 1], g[i << 1]), gg[i] = g[i << 1 | 1];
        }
        if (gg[0] == 0) ss += pp * cp(gg[0], gg[1]);
        if (gg[1] == 0) ss += pp * cp(gg[1], gg[0]);
      }
    }
    chmax(s, ss);
  }
  setp(15);
  print(s);
}
#include "YRS/Z_H/main.hpp"