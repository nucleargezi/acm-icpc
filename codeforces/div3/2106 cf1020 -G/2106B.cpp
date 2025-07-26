#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"

#define tests
void Yorisou() {
  LL(n, x);
  vector<int> ans(n);
  FOR(i, x) ans[i] = i;
  FOR(i, x, n - 1) ans[i] = n - i + x - 1;
  ans.back() = x;
  chmin(ans.back(), n - 1);
  print("{}", ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"