#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/graph/Apck/tree_diameter.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N, K);
  graph g(N);
  g.read_tree();
  Z [d, pa] = tree_diameter(g);
  int ans = N * 2 - len(pa), s = 0;
  if (K == 1) return print(ans);
  vc<char> vis(N);
  vc<int> dp(N);
  for (int x : pa) vis[x] = 1;
  Z f = [&](Z &f, int n, int fa) -> void {
    for (Z &&e : g[n]) if (e.to != fa) {
      int w = (vis[e.to] and vis[n]) ? -1 : 1;
      f(f, e.to, n);
      chmax(s, dp[e.to] + dp[n] + w);
      chmax(dp[n], dp[e.to] + w);
    }
  };
  f(f, pa[0], -1);
  print(ans - s + 1);
}
#include "YRS/Z_H/main.hpp"