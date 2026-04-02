#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n);
  S(s);
  vector<int> v[26];
  FOR(i, n) v[s[i] - 'a'] += i;
  FOR(i, 26) {
    if (len(v[i]) < 5) continue;
    int p = v[i][4];
    FOR(k, 26) {
      int idx = upper_bound(v[k], p);
      if (idx + 6 >= len(v[k])) continue;
      int nxp = v[k][idx + 6];
      FOR(j, 26) {
        int idx = upper_bound(v[j], nxp);
        if (idx + 4 >= len(v[j])) continue;
        iroha UL(string(5, i + 'a') + string(7, k + 'a') + string(5, j + 'a'));
      }
    }
  }
  UL("none");
}
#include "MeIoN_Lib/Z_H/main.hpp"