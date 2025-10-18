#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/ge/all.hpp"
#include "YRS/random/rng.hpp"

// #define tests
using RE = double;
using P = point<RE>;
void Yorisou() {
  INT(N);
  VEC(P, p, N);
  if (N < 600) {
    RE ans = inf<RE>;
    FOR(i, N) FOR(k, i + 1, N) FOR(j, k + 1, N) {
      chmin(ans, dist(p[i], p[k]) + dist(p[k], p[j]) + dist(p[j], p[i]));
    }
    return setp(6), UL(ans);
  }
  RE ans = inf<RE>;
  RE th = rng() % 314 / 100.L;
  FOR(i, N) p[i] = p[i].rotate(th);
  sort(p);
  for (int i = 0; i < N; ++i) {
    for (int k = i + 1; k < i + 30 and k < N; ++k) {
      for (int j = k + 1; j < k + 30 and j < N; ++j) {
        chmin(ans, dist(p[i], p[k]) + dist(p[k], p[j]) + dist(p[j], p[i]));
      }
    }
  }
  setp(6);
  UL(ans);
}
#include "YRS/Z_H/main.hpp"