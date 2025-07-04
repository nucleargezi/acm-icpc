#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/PR/primtable.hpp"

#define tests
meion pr = primtable(214514);
void Yorisou() {
  LL(n);
  vector<int> ans(n + 1);
  vector<u8> f(n + 1);
  int L = upper_bound(pr, n / 2);
  FOR_R(i, L) {
    int e = pr[i];
    vector<int> v;
    FOR(k, e, n + 1, e) {
      if (not f[k]) v += k;
    }
    int sz = len(v);
    FOR(i, sz) {
      int x = v[i], y = v[(i + 1) % sz];
      ans[x] = y;
      f[x] = 1;
    }
  }
  FOR(i, 1, n + 1) if (not f[i]) ans[i] = i;
  ans.erase(ans.begin());
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"