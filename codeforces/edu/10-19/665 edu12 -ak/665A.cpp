#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(a, ta, b, tb);
  S(t);
  ll st = 60 * std::stoll(t.substr(0, 2)) + std::stoll(t.substr(3, 2)),
     ed = st + ta, ans = 0;
  FOR(t, 300, 1440, b) {
    ll bs = t, be = t + tb;
    ans += be > st and bs < ed;
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"