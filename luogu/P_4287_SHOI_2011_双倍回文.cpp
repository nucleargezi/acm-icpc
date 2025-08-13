#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/string/pam.hpp"

// #define tests
void Yorisou() {
  INT(n);
  S(s);
  PAM seg(s);
  vector lps = seg.keis_lps();
  vector le = seg.lps_len_per_node();
  const int N = len(lps);
  ll ans = 0;
  for (int i = 2; i < N; ++i) {
    auto [c, l] = lps[i];
    int mn = l - le[i];
    if (l < 4 or l % 4 or (l / 2) % mn) continue;
    chmax(ans, l);
  }
  UL(ans);
}
#include "YRS/Z_H/main.hpp"