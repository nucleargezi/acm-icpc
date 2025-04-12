#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  S(s, t);
  if (s == t and s == "0") iroha UL("OK");
  char min('9');
  const int n{len(s)};
  FOR(i, n) if (s[i] != '0') chmin(min, s[i]);
  FOR(i, n) if (s[i] == min) {
    string ans = s.substr(0, i);
    if (i != n - 1) ans += s.substr(i + 1);
    sort(ans);
    ans = min + ans;
    iroha UL(ans == t ? "OK" : "WRONG_ANSWER");
  }
  UL("WRONG_ANSWER");
}

// 日々を貪り尽くしてきた
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(12);
  // freopen("in","r",stdin);
  // freopen("outt","w",stdout);
  before();
#ifdef tests
  LL(t); FOR(t)
#endif
  Yorisou();
  iroha 0;
}