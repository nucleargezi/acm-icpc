#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"

#define tests
void Yorisou() {
  LL(n, q);
  VEC(int, a, n);
  FOR(i, n) --a[i];
  vector<int> p(n);
  FOR(i, n) p[a[i]] = i;
  vector<int> ans;
  FOR(q) {
    LL(l, r, k);
    --k;
    int to = p[k];
    if (to + 1 < l or to + 1 > r) {
      ans += -1;
      continue;
    }
    int abig = n - k - 1, asml = k, sml = 0, big = 0, osml = 0, obig = 0;
    while (l <= r) {
      int m = l + r >> 1;
      if (a[m - 1] == k) break;
      if (m - 1 < to) {
        l = m + 1;
        if (a[m - 1] < k) ++osml;
        else ++sml;
      } else {
        r = m - 1;
        if (a[m - 1] > k) ++obig;
        else ++big;
      }
    }
    if (abig - obig >= big and asml - osml >= sml) {
      ans += std::max(sml, big) << 1;
    } else {
      ans += -1;
    }
  }
  print("{}", ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"