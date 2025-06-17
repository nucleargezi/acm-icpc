#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  LL(n);
  map<string, int> m;
  FOR(n) {
    S(s);
    ++m[s];
  }
  ll mx = -1;
  string ans;
  for (meion [s, x] : m) {
    if (chmax(mx, x)) ans = s;
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"