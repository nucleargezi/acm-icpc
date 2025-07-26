#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"

// #define tests
using mint = M99;
void Yorisou() {
  LL(n);
  VVEC(mint, a, n, n);
  mint ans = 1, v = 1;
  FOR(i, n) FOR(k, i + 1, n) {
    while (a[i][i].val) {
      mint x = a[k][i] / a[i][i];
      FOR(j, i, n)
        a[k][j] -= x * a[i][j];
      swap(a[i], a[k]), v = -v;
    }
    swap(a[i], a[k]), v = -v;
  }
  ans *= v;
  FOR(i, n) ans *= a[i][i];
  print("{}", ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"