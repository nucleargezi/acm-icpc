#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/gg/bs.hpp"
#include "YRS/ds/bit/bit.hpp"
#include "YRS/al/m/add.hpp"

TE void tree_dec(const vc<vc<edge_w<T>>> &g, var f) {
  int N = si(g);
  vc<int> sz(N), fa(N), v(N), d(N), p(N), in(N + 1);
  vc<T> dis(N);
  vc<char> del(N);
  Z dfs = [&](Z &&go, int s) -> void {
    int n = 1;
    v[0] = s, fa[s] = -1;
    FOR(i, n) {
      int a = v[i];
      sz[a] = 1;
      for (int b : g[a]) if (b != fa[a] and not del[b]) fa[b] = a, v[n++] = b;
    }
    int i = n;
    while (sz[v[--i]] < (n + 1) / 2) sz[fa[v[i]]] += sz[v[i]];
    int c = v[i], r = 1, cc = 2;
    v[0] = c, dis[0] = 0, p[0] = -1, in[0] = 0, in[1] = 1, d[0] = 0;
    for (Z &&a : g[c]) if (not del[a]) {
      int l = r;
      v[r] = a, dis[r] = a.w, d[r] = 1, p[r++] = 0;
      FOR(k, l, r) {
        int b = v[k], e = v[p[k]];
        for (Z &&x : g[b]) if (x != e and not del[x])
          v[r] = x, dis[r] = dis[k] + x.w, d[r] = d[k] + 1, p[r++] = k;
      }
      in[cc++] = r;
    }
    f(span(v.data(), n), span(dis.data(), n),
        span(p.data(), n), span(in.data(), cc));
    del[c] = 1;
    for (int a : g[c]) if (not del[a]) go(go, a);
  };
  if (N) dfs(dfs, 0);
}

TE void tree_dec_pair(const vc<vc<T>> &g, var f) {
  tree_dec(g, [&](var v, var dis, var p, var in) {
    Z dfs = [&](Z &&go, int l, int r) -> void {
      if (r - l < 2) return;
      int m = lower_bound(bg(in) + l + 1, bg(in) + r,
          (in[l] + in[r]) / 2) - bg(in);
      if (m == r or (m > l + 1 and
          max(in[m - 1] - in[l], in[r] - in[m - 1]) <
          max(in[m] - in[l], in[r] - in[m]))) --m;
      f(v, dis, p, in[l], in[m], in[r]);
      go(go, l, m), go(go, m, r);
    };
    dfs(dfs, 0, si(in) - 1);
  });
}

void Yorisou() {
  INT(N);
  vc<vc<edge_w<int>>> g(N);
  FOR(N - 1) {
    INT(a, b, c);
    --a, --b;
    if (a > b) swap(a, b);
    g[a].ep(b, c);
    g[b].ep(a, c);
  }
  INT(K);

  vc<int> dis(N);
  int s = 0;
  bit_t<Add<int>> bit(K + 1);
  tree_dec_pair(g, [&](var v, var D, var p, int l, int m, int r) {
    FOR(i, l, m) if (int d = D[i]; d <= K) bit.add(d, 1);
    FOR(i, m, r) if (int d = D[i]; d <= K) s += bit.prod(K - d + 1);
    FOR(i, l, m) if (int d = D[i]; d <= K) bit.add(d, -1);
  });
  print(s);
}

int main() { Yorisou(); }