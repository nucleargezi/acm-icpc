#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/string/pam.hpp"

void before() {}

// #define tests
void Yorisou() {
  S(s);
  PAM<26> pam(s, 'a');
  ll ans = 0;
  for (meion [x, y] : pam.keisan()) {
    chmax(ans, 1ll * x * y);
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"