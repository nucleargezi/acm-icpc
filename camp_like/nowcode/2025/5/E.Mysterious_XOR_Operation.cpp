#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/Z_H/MeioN.hpp"
// #include "MeIoN_Lib/IO/fmt.hpp"

// #define tests
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  int B = 30;
  vector<u8> v(n);
  ll ans = 0;
  FOR(k, B) {
    ll A = 0, B = 0, C = 0, D = 0;
    FOR(i, n) {
      int x = (a[i] >> k) & 1;
      if (not v[i])
        (x ? B : A)++;
      else
        (x ? D : C)++;
    }
    ans += (A * B + C * D) * (1 << k);
    FOR(i, n) {
      v[i] ^= (a[i] >> k & 1);
    }
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"