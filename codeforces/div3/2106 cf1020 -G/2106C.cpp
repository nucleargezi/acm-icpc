#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"

#define tests
void Yorisou() {
  LL(n, k);
  VEC(int, a, n);
  VEC(int, b, n);
  ll mx = -1;
  FOR(i, n) if (b[i] != -1) chmax(mx, a[i] + b[i]);
  FOR(i, n) if (b[i] != -1) if (mx != a[i] + b[i]) iroha print("0");
  FOR(i, n) {
    if (b[i] == -1 and mx != -1 and (a[i] > mx or mx - a[i] > k))
      iroha print("0");
  }
  int c = 0;
  vector<int> x;
  FOR(i, n) if (b[i] == -1) ++c, x += a[i];
  if (c == n) {
    meion [l, r] = MINMAX(x);
    print("{}", l - r + k + 1);
  } else {
    print("{}", 1);
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"