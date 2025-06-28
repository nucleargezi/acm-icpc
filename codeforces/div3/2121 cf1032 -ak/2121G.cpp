#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

#define tests
void Yorisou() {
  LL(n);
  vector<int> s(n);
  FOR(i, n) {
    CH(c);
    s[i] = (c == '1') ? 1 : -1;
  }
  ll ans = 0;
  FOR(i, 1, n + 1) ans += i * (n - i + 1);
  vector c = pre_sum(s);
  sort(c);
  FOR(i, n + 1) ans += c[i] * i - c[i] * (n - i);
  UL(ans >> 1);
}
#include "MeIoN_Lib/Z_H/main.hpp"