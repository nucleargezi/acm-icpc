#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
#include "YRS/ds/wave/wave_mat.hpp"
#include "YRS/ds/static_range_group.hpp"

struct MX {
  using X = PLL;
  static constexpr inline X op(const X &x, const X &y) {
    return {x.fi + y.fi, x.se + y.se};
  }
  static constexpr inline X inv(const X &x) {
    return {-x.fi, -x.se};
  }
  static constexpr inline X unit() { return {}; }
  static constexpr bool commute = 1;
};
using Seg = static_range_group<MX>;
using DS = wave_mat<int, 0, MX, Seg>;
void Yorisou() {
  INT(N, Q);
  VEC(T3<int>, a, N);
  sort(a, [&](T3<int> &x, T3<int> &y) -> bool {
    Z [i, j, k] = x;
    Z [e, r, t] = y;
    if (i != e) return i > e;
    return j < r;
  });
  DS wm(N, [&](int i) -> pair<int, PLL> {
    Z [x, y, z] = a[i];
    return {y, {z, 1ll * y * z}};
  });
  FOR(Q) {
    LL(w, L);
    int i = bina([&](int r) -> bool {
      if (r == N + 1) return 1;
      PLL s = wm.pre_prod(0, r, inf<int>);
      if (s.fi < L) return 0;
      int y, c;
      tie(y, c, s) = wm.max_right([&](int y, int cnt, PLL s) {
        return s.fi < L;
      }, 0, r);
      if (s.se >= w) return 0;
      Z [cnt, sw] = wm.prod(0, r, y, y + 1);
      return s.se + (L - s.fi) * (sw / cnt) <= w;
    }, N + 1, 0);
    print(i == N + 1 ? -1 : get<0>(a[i - 1]));
  }
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"