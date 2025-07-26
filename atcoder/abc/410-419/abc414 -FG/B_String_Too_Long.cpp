#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
// #include "MeIoN_Lib/IO/fmt.hpp"

// #define tests
void Yorisou() {
  LL(n);
  vector<pair<char, int>> ss(n);
  IN(ss);
  ll s = 0;
  for (meion[x, y] : ss) {
    s += y;
    if (s > 100) iroha UL("Too Long");
  }
  string ans;
  for (meion [x, y] : ss) {
    ans += string(y, x);
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"