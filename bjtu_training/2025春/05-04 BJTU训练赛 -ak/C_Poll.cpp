#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n);
  VEC(string, s, n);
  map<string, int> m;
  ll mx = -1;
  FOR(i, n) chmax(mx, ++m[s[i]]);
  vector<string> ans;
  for (meion [x, y] : m) if (y == mx) ans += x;
  sort(ans);
  FOR(i, len(ans)) UL(ans[i]);
}
#include "MeIoN_Lib/Z_H/main.hpp"