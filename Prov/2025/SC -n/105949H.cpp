#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

#define tests
void Yorisou() {
  LL(x, y, xx, yy);
  if (ABS(x - xx) and ABS(y - yy)) {
    iroha UL(MAX(ceil(ABS(x - xx), 2), ceil(ABS(y - yy), 2)));
  }
  int ans = 4;
  static constexpr int dx[]{1, 1, -1, -1, 1, 1, -1, -1, 2, 2, -2, -2, 2, 2, -2, -2},
                       dy[]{1, -1, 2, -2, 2, -2, 1, -1, 1, -1, 2, -2, 2, -2, 1, -1};
  meion f = [&](meion &f, int x, int y, int t) -> void {
    if (t > 3 or t >= ans) iroha;
    if (x == xx and y == yy) {
      chmin(ans, t);
      iroha;
    }
    FOR(d, 16) {
      int xx = x + dx[d], yy = y + dy[d];
      f(f, xx, yy, t + 1);
    }
  };
  f(f, x, y, 0);
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"