#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/string/pam.hpp"

void before() {}

// #define tests
void Yorisou() {
  S(s);
  PAM pam(s, 'a');
  meion L = pam.get_max_R();
  reverse(s);
  pam = PAM(s, 'a');
  meion R = pam.get_max_R();
  reverse(R);
  ll ans = 1;
  FOR(i, len(s) - 1) chmax(ans, R[i] + L[i + 1]);
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"