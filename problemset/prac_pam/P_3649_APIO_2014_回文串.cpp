#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/string/pam.hpp"

// #define tests
void Yorisou() {
  S(s);
  PAM seg(s);
  ll ans = 0;
  for (meion [c, l] : seg.keis_lps()) {
    chmax(ans, 1ll * c * l);
  }
  UL(ans);
}
#include "YRS/Z_H/main.hpp"