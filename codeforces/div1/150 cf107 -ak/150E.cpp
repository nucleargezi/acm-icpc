#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ttr/tree_dec.hpp"
#include "YRS/ds/seg/seg_t.hpp"
#include "YRS/al/m/max.hpp"

void Yorisou() {
  INT(N, dl, dr);
  ++dr;
  vc<vc<edge_w<int>>> g(N);
  FOR(N - 1) {
    INT(a, b, c);
    --a, --b;
    g[a].ep(b, c);
    g[b].ep(a, c);
  }
  if (dl == 1) {
    int a, b, mx = -1;
    FOR(n, N) for (Z &&e : g[n]) if (chmax(mx, e.w)) {
      tie(a, b) = {n, e.t};
    }
    print(a, b);
  }
  
  vc<int> ew(N), L(N), w(N), q{0};
  vc<char> vis(N);
  vis[0] = 1;
  FOR(i, N) {
    int n = q[i];
    L[n] = i;
    for (Z &&e : g[n]) {
      if (not vis[e]) {
        vis[e] = 1;
        ew[e] = e.w;
        q.ep(e);
      }
    }
  }
  Z fe = [&](int a, int b) { return L[a] < L[b] ? b : a; };
  
  vc<int> d, dis;
  seg_t<Max<ll>> seg(N);
  int mx = -1, lm = QMAX(ew) + 1;
  PII ans;
  Z [fa, V] = dec_pr(g);
  dec1(fa, V, [&](const vc<int> &fa, const vc<int> &vs, int l, int r, int L, int R) {
    int n = si(fa);
    d.assign(n, 0);
    dis.assign(n, 0);
    bina<0>([&](int x) -> bool {
      FOR(i, 1, n) {
        int fid = fa[i], f = vs[fid], t = vs[i];
        d[i] = d[fid] + (ew[fe(f, t)] < x ? -1 : 1);
        dis[i] = min(dis[fid] + 1, dr);
      }
      FOR(i, l, r) if (dis[i] < dr) seg.add(dis[i], ll(d[i]) << 32 | vs[i]);
      bool ok = 0;
      FOR(i, L, R) {
        int g = dis[i], val = d[i];
        if (g < dr) {
          ll dat = seg.prod(max(dl - g, 0), dr - g);
          if (dat == -inf<ll>) continue;
          val += dat >> 32;
          if (val >= 0) {
            chmax(mx, x);
            ok = 1;
            ans = {vs[i], dat};
            break;
          }
        }
      }
      FOR(i, l, r) if (dis[i] < dr) seg.set(dis[i], -inf<ll>);
      return ok;
    }, mx, lm);
  });
  print(ans.fi + 1, ans.se + 1);
}

int main() {
  Yorisou();
  return 0;
}