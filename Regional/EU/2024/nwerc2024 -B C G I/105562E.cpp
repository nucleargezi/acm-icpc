#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint_pow.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, k);
  S(s);
  string ans;
  FOR(i, n) {
    ans += s[i * mod_pow(2, k, n) % n];
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"