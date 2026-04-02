#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/graph/Apck/Basic.hpp"

// #define tests
int N;
void yorisou() {
  graph g(N);
  g.read_tree<1>();
  int ans = 0;
  Z f = [&](Z &f, int n, int fa) -> vector<int> {
    vector<int> dp(2019);
    dp[0] = 1;
    for (Z &e : g[n]) {
      if (e.to == fa) continue;
      Z sdp = f(f, e.to, n);
      FOR(i, 2019) ans += sdp[i] * dp[(2019 * 10 - i - e.cost) % 2019];
      FOR(i, 2019) dp[(i + e.cost) % 2019] += sdp[i];
    }
    return dp;
  };
  f(f, 0, -1);
  print(ans);
}
void Yorisou() {
  while (IN(N)) yorisou();
}
#include "YRS/Z_H/main.hpp"