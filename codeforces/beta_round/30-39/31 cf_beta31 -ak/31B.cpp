#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  S(s);
  ll n = len(s);
  FOR(i, n - 1) if (s[i] == s[i + 1] and s[i] == '@') iroha UL("No solution");
  FOR(i, n - 2) if (s[i] == s[i + 2] and s[i] == '@') iroha UL("No solution");
  if (s[0] == '@' or s[n - 1] == '@') iroha UL("No solution");
  if (std::ranges::count(s, '@') == 0) iroha UL("No solution");
  string ans{};
  FOR(i, n) {
    ans += s[i];
    if (s[i] == '@') {
      ans += s[++i];
      ans += ',';
    }
  }
  FOR_R(i, len(ans)) if (ans[i] == ',') {
    ans.erase(i, 1);
    break;
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"