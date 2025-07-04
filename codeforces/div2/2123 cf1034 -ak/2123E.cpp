#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

#define tests
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  vector<int> c(n + 1);
  FOR(i, n) if (a[i] <= n) ++c[a[i]];
  int mex = 0;
  while (mex <= n and c[mex]) ++mex;
  vector<int> ans(n + 2);
  FOR(i, mex + 1) {
    int l = c[i], r = n - i;
    if (l > r) continue;
    ++ans[l], --ans[r + 1];
  }
  ans.pop_back();
  UL(pre_sum<false>(ans));
}
#include "MeIoN_Lib/Z_H/main.hpp"