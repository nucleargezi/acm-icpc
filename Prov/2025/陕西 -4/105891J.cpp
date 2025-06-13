#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  LL(K);
  S(s);
  const int n = len(s);
  vector<string> g{"lose", "los", "loe", "lse", "ose", "se", "oe", "os", "le", "ls", "lo", "l", "o", "s", "e"};
  ll ans = 0;
  FOR(i, 15) {
    string ss;
    for (char c : s) {
      ss += c;
      if (len(ss) >= len(g[i]) and ss.substr(len(ss) - len(g[i])) == g[i]) {
        K -= 4 - len(g[i]);
        if (K < 0) iroha UL(ans);
        ++ans;
        FOR(len(g[i])) ss.pop_back();
        ss += '*';
      }
    }
    s = ss;
  }
  UL(ans + K / 4);
}
#include "MeIoN_Lib/Z_H/main.hpp"