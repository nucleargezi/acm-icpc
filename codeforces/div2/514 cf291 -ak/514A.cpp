#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  S(s);
  ll n = len(s);
  bool f = 1;
  FOR(i, n) {
    ll c = s[i] - '0';
    c = 9 - c;
    if (not f or (f and c)) chmin(s[i], '0' + c);
    f = 0;
  }
  UL(s);
}
#include "MeIoN_Lib/Z_H/main.hpp"