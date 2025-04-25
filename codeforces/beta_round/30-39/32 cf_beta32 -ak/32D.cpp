#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, m, k);
  VEC(string, a, n);
  vector<PLL> ans;
  vector<ll> R;
  FOR(r, 1, n / 2 + 1) {
    const ll dx[]{r, -r, 0, 0}, dy[]{0, 0, r, -r};
    FOR(x, n) FOR(y, m) {
      if (a[x][y] == '.' or MIN(x, y) - r < 0 or x + r > n - 1 or y + r > m - 1)
        continue;
      bool f = 1;
      FOR(i, 4) {
        f &= a[x + dx[i]][y + dy[i]] == '*';
      }
      if (f) ans += PLL(x + 1, y + 1), R += r;
    }
  }
  if (--k < len(ans)) {
    const ll dx[]{-R[k], R[k], 0, 0}, dy[]{0, 0, -R[k], R[k]};
    meion [x, y] = ans[k];
    UL(x, y);
    FOR(i, 4) UL(x + dx[i], y + dy[i]);
  } else {
    UL(-1);
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"