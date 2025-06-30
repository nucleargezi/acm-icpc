#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/ds/basic/queue.hpp"

#define tests
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  vector<PLL> c;
  FOR(i, 1, n) c.emplace_back(a[i], i);
  sort(c);
  vector<int> dp(n);
  queue<int> q;
  dp[0] = 1;
  q.emplace_back(0);
  int p = 0;
  while (not q.empty()) {
    int f = q.pop();
    while (p < len(c) and c[p].first <= a[f] * 2) {
      int t = c[p].second;
      dp[t] = dp[f] + 1;
      if (t == n - 1) {
        iroha UL(dp[t]);
      }
      q.emplace_back(t);
      p++;
    }
  }
  UL(-1);
}
#include "MeIoN_Lib/Z_H/main.hpp"