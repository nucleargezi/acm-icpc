#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  S(s, t);
  ll n = len(s), m = len(t);
  FOR(i, n - m + 1) {
    bool f = 1;
    FOR(k, m) {
      f &= s[i + k] == '?' or s[i + k] == t[k];
    }
    if (f) iroha Yes();
  }
  No();
}
#include "MeIoN_Lib/Z_H/main.hpp"