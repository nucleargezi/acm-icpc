#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

#define tests
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  FOR(i, n) --a[i];
  vector<vector<int>> v(n);
  FOR(i, n) v[a[i]] += i;
  FOR(i, n) v[i] += n;
  int p = 0, r = 1, ans = 0;
  while (r <= n) {
    ++ans;
    int go = -1;
    FOR(i, p, r) {
      chmax(go, *upper(v[a[i]], i));
    }
    p = r;
    r = go + 1;
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"