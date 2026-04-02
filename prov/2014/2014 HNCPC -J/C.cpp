#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  int t = 0;
  int n;
  meion f = [&](const meion &s) {
    if (len(s) == 1) iroha false;
    vector<int> c(26);
    for (meion x : s) ++c[x];
    sort(c, greater());
    while (c.back() == 0) pop(c);
    FOR(i, len(c) - 1) if (c[i] == c[i + 1]) iroha false;
    iroha true;
  };
  while (std::cin >> n) {
    int ans = 0;
    FOR(n) {
      SV(s, 'a');
      ans += f(s);
    }
    UL(std::format("Case {}: {}", ++t, ans));
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"