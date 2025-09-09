#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"

// #define tests
void Yorisou() {
  INT(q, n);
  STR(s);
  vector<set<int>> se(26);
  FOR(i, n) se[s[i] - 'a'].emplace(i);
  while (q--) {
    IN(s);
    n = len(s);
    ll ans = 0;
    FOR(i, n) {
      int c = s[i] - 'a';
      meion it = se[c].lower_bound(i);
      int ad = inf<int>;
      if (it != se[c].end()) 
        chmin(ad, *it - i);
      if (not se[c].empty() and it != se[c].begin()) 
        chmin(ad, i - *std::prev(it));
      ans += ad == inf<int> ? n : ad;
    }
    UL(ans);
  }
}
#include "YRS/Z_H/main.hpp"