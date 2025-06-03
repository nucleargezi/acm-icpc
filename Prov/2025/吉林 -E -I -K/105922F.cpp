#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  LL(n);
  S(s);
  ll ans = 0;
  FOR(i, n) FOR(k, i + 1, n) {
    if (s[i] == 'e' and s[k] == 'f') ans += k - i;
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"