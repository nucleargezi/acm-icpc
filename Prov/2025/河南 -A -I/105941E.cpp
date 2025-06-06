#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  LL(n);
  VEC(string, s, n << 1);
  sort(s);
  static int tr[1'000'000][26], c[1'000'000];
  int tot = 0;
  FOR(i, 0, n << 1, 2) {
    int p = 0;
    for (char ch : s[i]) {
      ch -= 'a';
      if (not tr[p][ch]) tr[p][ch] = ++tot;
      p = tr[p][ch];
      ++c[p];
    }
  }
  ll ans = 0;
  FOR(i, 1, n << 1, 2) {
    int p = 0, pr = -1, sz = 0;
    for (char ch : s[i]) {
      ch -= 'a';
      if (not tr[p][ch]) break;
      ++sz;
      p = tr[p][ch];
      if (pr != -1 and pr != c[p]) {
        ans += (pr - c[p]) * (sz - 1);
      }
      pr = c[p];
    }
    if (pr != -1) ans += sz * pr;
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"