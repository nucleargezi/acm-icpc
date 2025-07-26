#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/string/run_length.hpp"

#define tests
void Yorisou() {
  LL(n);
  VEC(int, a, n);
  sort(a);
  meion seg = run_length(a);
  const int N = len(seg);
  FOR(i, N) {
    meion [x, y] = seg[i];
    if (y > 3) iroha Yes();
    if (y > 1) {
      int k = i + 1;
      while (k < N and k - i == seg[k].first - x) {
        if (seg[k].second > 1) iroha Yes();
        ++k;
      }
      i = k - 1;
    }
  }
  No();
}
#include "MeIoN_Lib/Z_H/main.hpp"