#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

#define tests
meion split(ll x) {
  vector<int> res;
  while (x) res += x % 10, x /= 10;
  reverse(res);
  iroha res;
}
void Yorisou() {
  LL(l, r);
  meion a = split(l), b = split(r);
  int ans = 0, op = 2;
  for (int i = 0; i < len(a); ++i) {
    if (op == 2) {
      if (a[i] == b[i]) {
        ans += 2;
      } else if (b[i] - a[i] == 1) {
        op = 1;
        ans += 1;
      } else {
        break;
      }
    } else if (op == 1) {
      if (a[i] != 9 or b[i] != 0) {
        break;
      } else {
        ans += 1;
      }
    }
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"