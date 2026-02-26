#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  LL(n);
  VEC(int, a, n);
  VEC(int, b, n);
  int ans = inf<int>;
  FOR(i, n) {
    min_heap<PII> q;
    FOR(i, n) q.emplace(a[i], 0);
    int r = 0;
    FOR(k, n) {
      meion [x, c] = pop(q);
      q.emplace(x + b[(i + k) % n] / 2, c + 1);
      chmax(r, c + 1);
    }
    chmin(ans, r);
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"