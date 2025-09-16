#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  S(s);
  map<char, ll> m;
  ll ans = 0;
  for (char c : s) ++m[c];
  for (meion [a, b] : m) {
    ans += b * b;
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"