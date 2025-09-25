#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/graph/Apck/Basic.hpp"
#include "YRS/ds/basic/retsu.hpp"
#include "YRS/ds/basic/queue.hpp"

// #define tests
using A = retsu<int>;
void Yorisou() {
  INT(N, K);
  VEC(int, d, N - 1);
  d.insert(d.begin(), 0);
  graph g(N);
  g.read_tree();
  A dis(N, N, inf<int>);
  FOR(i, N) {
    dis[i][i] = 0;
    queue<int> q;
    q.eb(i);
    while (not q.empty()) {
      int n = q.pop();
      for (Z &&e : g[n]) {
        if (chmin(dis[i][e.to], dis[i][n] + 1)) q.eb(e.to);
      }
    }
  }

  A dp(N, N);
  vector<int> mn(N, -1);
  Z f = [&](Z &f, int n, int fa) -> void {
    FOR(i, N) dp[n][i] = d[dis[n][i]] + K;
    for (Z &&e : g[n]) {
      int t = e.to;
      if (t == fa) continue;
      f(f, t, n);
      FOR(i, N)
        dp[n][i] += std::min(mn[t] == -1 ? 0 : dp[t][mn[t]], dp[t][i] - K);
    }
    mn[n] = std::min_element(dp[n], dp[n] + N) - dp[n];
  };
  f(f, 0, -1);
  print(dp[0][mn[0]]);
  vector<int> ans(N);
  Z r = [&](Z &r, int n, int fa, int ac) -> void {
    ans[n] = ac + 1;
    for (Z &&e : g[n]) {
      int t = e.to;
      if (t == fa) continue;
      r(r, t, n, dp[t][mn[t]] < dp[t][ac] - K ? mn[t] : ac);
    }
  };
  r(r, 0, -1, mn[0]);
  print(ans);
}
#include "YRS/Z_H/main.hpp"