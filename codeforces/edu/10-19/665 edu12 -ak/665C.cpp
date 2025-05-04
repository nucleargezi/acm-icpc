#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  SV(s, 'a');
  ll n = len(s);
  FOR(i, n - 2) {
    if (s[i] == s[i + 1]) {
      FOR(t, 26) if (t != s[i] and t != s[i + 2]) {
        s[i + 1] = t;
        break;
      }
    }
  }
  if (s[n - 2] == s[n - 1]) {
    s[n - 1] = s[n - 2] ^ 1;
  }
  string ans;
  FOR(i, n) ans += 'a' + s[i];
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"