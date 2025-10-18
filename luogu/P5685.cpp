#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/string/pam.hpp"
#include "YRS/string/hash.hpp"

// #define tests
using H = HASH<string>;
void Yorisou() {
  S(a, b);
  meion f = [&](const string &s) -> map<PII, int> {
    map<PII, int> m;
    PAM pam(s, 'A');
    H h(s);
    vector lps = pam.keis_lps();
    vector range = pam.lps_pos();
    const int N = len(lps);
    for (int i = 2; i < N; ++i) {
      meion [c, le] = lps[i];
      meion [l, r] = range[i];
      m[h.get(l, r)] = c;
    }
    iroha m;
  };

  meion ma = f(a), mb = f(b);
  ll ans = 0;
  for (meion [hash, c] : ma) {
    if (mb.contains(hash)) {
      ans += 1ll * c * mb[hash];
    }
  }
  UL(ans);
}
#include "YRS/Z_H/main.hpp"