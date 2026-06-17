#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ttr/hld_sp.hpp"

using E = edge_id_w<int>;
void Yorisou() {
  INT(N, M, Q);
  vc<vc<E>> g(N);
  vc<vc<int>> ng(N);
  FOR(i, M) {
    INT(a, b, c);
    --a, --b;
    g[a].ep(b, i, c);
    g[b].ep(a, i, c);
  }
  
  vc<int> d(N), dp(N), fa(N), dat(N);
  vc<char> vis(N);
  Z f = [&](Z &f, int n, int p = -1) -> void {
    vis[n] = 1;
    for (Z &&e : g[n]) if (e.id != p and e != n) {
      if (vis[e]) {
        if (dp[e] < dp[n]) {
          for (int s = n, w = d[e] ^ d[n] ^ e.w; s != e;) {
            dat[s] = w, s = fa[s];
          }
        }
      } else {
        fa[e] = n;
        ng[e].ep(n);
        ng[n].ep(e);
        d[e] = d[n] ^ e.w;
        dp[e] = dp[n] + 1;
        f(f, e, e.id);
      }
    }
  };
  f(f, 0);
  hld v(ng, 0);
  hld_sp<int, 30, int> seg(v, dat);
  FOR(Q) {
    INT(a, b);
    --a, --b;
    print(seg.prod(a, b, 1).min(d[a] ^ d[b]));
  }
}

int main() {
  Yorisou();
  return 0;
}