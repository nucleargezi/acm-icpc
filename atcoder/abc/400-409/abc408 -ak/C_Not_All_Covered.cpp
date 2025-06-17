#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  LL(n, q);
  vector<ll> a(n + 1);
  FOR(q) {
    LL(l, r);
    --l;
    ++a[l], --a[r];
  }
  a = pre_sum<false>(a);
  a.pop_back();
  UL(QMIN(a));
}
#include "MeIoN_Lib/Z_H/main.hpp"