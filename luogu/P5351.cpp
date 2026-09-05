#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

TE void tree_dec(const vc<vc<T>> &g, var f) {
  int N = si(g);
  vc<int> sz(N), fa(N), v(N), p(N), in(N + 1), val(N),  d(N);
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
    v[0] = c, d[0] = 0, p[0] = -1, in[0] = 0, in[1] = 1;
    val[0] = 0;
    for (Z &&a : g[c]) if (not del[a]) {
      int l = r;
      v[r] = a, d[r] = 1, val[r] = a.w, p[r++] = 0;
      FOR(k, l, r) {
        int b = v[k], e = v[p[k]];
        for (Z &&x : g[b]) if (x != e and not del[x])
          v[r] = x, d[r] = d[k] + 1, val[r] = max(val[k], x.w), p[r++] = k;
      }
      in[cc++] = r;
    }
    f(span(v.data(), n), span(d.data(), n), span(val.data(), n),
        span(p.data(), n), span(in.data(), cc));
    del[c] = 1;
    for (int a : g[c]) if (not del[a]) go(go, a);
  };
  if (N) dfs(dfs, 0);
}

TE void tree_dec_pair(const vc<vc<T>> &g, var f) {
  tree_dec(g, [&](var v, var d, var val, var p, var in) {
    Z dfs = [&](Z &&go, int l, int r) -> void {
      if (r - l < 2) return;
      int m = lower_bound(bg(in) + l + 1, bg(in) + r,
          (in[l] + in[r]) / 2) - bg(in);
      if (m == r or (m > l + 1 and
          max(in[m - 1] - in[l], in[r] - in[m - 1]) <
          max(in[m] - in[l], in[r] - in[m]))) --m;
      f(v, d, val, p, in[l], in[m], in[r]);
      go(go, l, m), go(go, m, r);
    };
    dfs(dfs, 0, si(in) - 1);
  });
}

TP<TN T = int> struct sbit {
  int N;
  vc<T> a;
  sbit(int N) : N(N), a(N) {}
  void ad(int i) { for (; i < N; i |= i + 1) ++a[i]; }
  void sb(int i) { for (; i < N; i |= i + 1) --a[i]; }
  T f(int i) {
    T s = 0;
    for (; i > 0; i -= i & -i) s += a[i - 1];
    return s;
  }
  T operator()(int l, int r) { return f(r) - f(l); }
};

struct E {
  int t, w;
  operator int() const { return t; }
};

void Yorisou() {
  INT(N, L, R);
  ++R;
  vc<vc<E>> g(N);
  FOR(N - 1) {
    INT(a, b, c);
    --a, --b;
    g[a].ep(b, c), g[b].ep(a, c);
  }

  ll s = 0;
  sbit A(R), B(R);
  vc<PLL> ls(N), rs(N);
  tree_dec_pair(g, [&](var vs, var dis, var val, var fa, int l, int m, int r) {
    ls.clear(), rs.clear();
    FOR(i, l, m) if (ll d = dis[i]; d < R) ls.ep(val[i], d);
    FOR(i, m, r) if (ll d = dis[i]; d < R) rs.ep(val[i], d);
    sort(ls), sort(rs);
    for (int i = 0, k = 0, n = si(ls), m = si(rs); i < n or k < m; ) {
      if (i == n) {
        F1: ;
        var [v, d] = rs[k++];
        s += A(max<ll>(L - d, 0), R - d) * v;
        B.ad(d);
      } else if (k == m) {
        F2: ;
        var [v, d] = ls[i++];
        s += B(max<ll>(L - d, 0), R - d) * v;
        A.ad(d);
      } else {
        if (ls[i].fi > rs[k].fi) goto F1;
        else goto F2;
      }
    }
    for (var [v, d] : ls) A.sb(d);
    for (var [v, d] : rs) B.sb(d);
  });
  print(s << 1);
}

int main() { Yorisou(); }