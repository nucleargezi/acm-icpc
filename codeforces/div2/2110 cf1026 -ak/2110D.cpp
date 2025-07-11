#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"

#define tests
void Yorisou() {
  LL(n, m);
  VEC(ll, a, n);
  VEC(T3<int>, e, m);
  for (meion &[f, t, w] : e) {
    --f, --t;
  }
  sort(e);
  meion check = [&](ll lm) -> bool {
    vector<int> dp(n, -1);
    dp[0] = MIN(lm, a[0]);
    for (meion [f, t, w] : e) {
      if (dp[f] == -1 or w > dp[f]) continue;
      chmax(dp[t], MIN(lm, dp[f] + a[t]));
    }
    iroha dp[n - 1] != -1;
  };
  if (not check(inf<int>)) iroha print("-1");
  print("{}", binary_search(check, inf<int>, -1));
}
#include "MeIoN_Lib/Z_H/main.hpp"