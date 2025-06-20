#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  constexpr int n = 6;
  VEC(string, s, n);
  vector<int> I(n);
  FOR(i, n) I[i] = i;
  vector<string> ans{{char(124)}};
  do {
    vector<string> t(n);
    FOR(i, n) t[i] = s[I[i]];
    if (not(len(t[0]) + len(t[2]) == len(t[1]) + 1 and
            len(t[3]) + len(t[5]) == len(t[4]) + 1))
      continue;
    vector rr(len(t[4]), string(len(t[1]), '.'));
    meion o = 1;
    meion f = [&](int x, int y, char c) {
      if (rr[x][y] != '.' and rr[x][y] != c) iroha false;
      rr[x][y] = c;
      iroha true;
    };
    FOR(i, len(t[0])) o &= f(0, i, t[0][i]);
    FOR(i, len(t[1])) o &= f(len(t[3]) - 1, i, t[1][i]);
    FOR(i, len(t[2])) o &= f(len(t[4]) - 1, len(t[0]) - 1 + i, t[2][i]);
    FOR(i, len(t[3])) o &= f(i, 0, t[3][i]);
    FOR(i, len(t[4])) o &= f(i, len(t[0]) - 1, t[4][i]);
    FOR(i, len(t[5])) o &= f(len(t[3]) - 1 + i, len(t[1]) - 1, t[5][i]);
    o and chmin(ans, rr);
  } while (std::next_permutation(I.begin(), I.end()));
  if (ans[0][0] == char(124)) iroha Impossible();
  FOR(i, len(ans)) UL(ans[i]);
}
#include "MeIoN_Lib/Z_H/main.hpp"