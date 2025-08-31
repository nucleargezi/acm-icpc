#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/string/pam.hpp"

// #define tests
void Yorisou() {
  INT(n);
  S(s);
  PAM seg(s);
  meion lps = seg.keis_lps();
  meion le = seg.lps_len_per_node();
  ll ans = 0;
  const int N = len(le);
  for (int i = 2; i < N; ++i) {
    meion [c, l] = lps[i];
    int d = l - le[i];
    if (l < 2 or not d or l % d) continue;
    ans += 1ll * c * (l / d - 1);
  }
  UL(ans);
}
#include "YRS/Z_H/main.hpp"