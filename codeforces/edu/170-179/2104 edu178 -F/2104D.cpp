#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/PR/primtable.hpp"

vector ps = pre_sum(primtable<ll>(6666666));
void before() {}

#define tests
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  sort(a, greater());
  a = pre_sum(a);
  ll mx = 0;
  FOR(i, 1, n + 1) {
    if (a[i] >= ps[i])
      mx = i;
    else
      break;
  }
  UL(n - mx);
}
#include "MeIoN_Lib/Z_H/main.hpp"