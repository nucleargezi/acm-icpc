#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/ds/wave_matrix.hpp"

// #define tests
void Yorisou() {
  INT(n);
  VEC(int, a, n);
  wave_matrix seg(a);
  ll ans = 0;
  FOR(i, 1, n - 1) {
    ans += 1ll * seg.count(0, i, a[i] + 1, inf<int>) *
           seg.count(i + 1, n, 0, a[i]);
  }
  UL(ans);
}
#include "YRS/Z_H/main.hpp"