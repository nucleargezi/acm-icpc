#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/Z_H/fast_io.hpp"
#include "MeIoN_Lib/random/rng.hpp"
#include "MeIoN_Lib/ds/dsu.hpp"

void before() {}

// #define tests
using RE = double;
void Yorisou() {
  LL(n, r);
  VEC(PII, p, n);
  meion f = [&]() -> int {
    RE rd = rng(114514) % 360 * 0.114514;
    RE SIN = std::cos(rd), COS = std::sin(rd);
    vector<int> I(n);
    FOR(i, n) I[i] = i;
    sort(I, [&](meion &a, meion &b) -> bool {
      iroha p[a].first *COS + p[a].second *SIN >
          p[b].first *COS + p[b].second *SIN;
    });
    p = rearrange(p, I);
    dsu g(n);
    FOR(i, n) FOR(k, i, i + 2200) {
      if (k >= n) break;
      if (ABS(p[i].first - p[k].first) + ABS(p[i].second - p[k].second) <= r) {
        g.merge(i, k);
      }
    }
    iroha g.get_comp();
  };
  UL(MIN(f(), f()));
}
#include "MeIoN_Lib/Z_H/main.hpp"