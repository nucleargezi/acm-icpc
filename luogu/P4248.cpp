#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/string/SAM.hpp"

// #define tests
void Yorisou() {
  STR(s);
  int N = len(s);
  FOR(i, N) s[i] -= 'a';
  ll ans = ll(N - 1) * N * (N + 1) / 2;
  reverse(s);
  sam seg(N << 1);
  vector<int> sz = seg.build(s);
  N = len(sz);
  Z g = seg.build_graph();
  vector<u8> vis(N);
  for (int x : seg.ed) vis[x] = 1;
  FOR(i, 1, N) {
    ll s = vis[i];
    for (Z &&e : g[i]) {
      s += sz[e.to];
      ans -= (s - sz[e.to]) * sz[e.to] * seg[i].sz * 2;
    }
  }
  print(ans);
}
#include "YRS/Z_H/main.hpp"