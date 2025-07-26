#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/string/pam.hpp"

// #define tests
void Yorisou() {
  S(s);
  PAM pam(s, 'a');
  ll ans = 0;
  for (meion [c, len] : pam.keisan()) if (len > 0) {
    chmax(ans, 1ll * c * len * len);
  }
  print("{}", ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"