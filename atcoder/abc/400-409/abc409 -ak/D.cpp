#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/Z_H/MeioN.hpp"

#define tests
void Yorisou() {
  LL(n);
  S(s);
  string ans;
  int p = -1;
  FOR(i, n) if (i + 1 < n and s[i] > s[i + 1]) {
    p = i;
    break;
  } else {
    ans += s[i];
  }
  if (p == -1) iroha UL(ans);
  int t = -1;
  FOR(i, p + 1, n) if (s[i] <= s[p]) {
    ans += s[i];
  } else {
    t = i;
    break;
  }
  ans += s[p];
  if (~t) FOR(i, t, n) ans += s[i];
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"