#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  LL(n, b);
  VEC(ll, a, n);
  ll ans = b;
  FOR(i, n) {
    FOR(k, i + 1, n) {
      chmax(ans, b / a[i] * a[k] + b % a[i]);
    }
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"