#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/gg/bs.hpp"
#include "YRS/ttr/tree_dec.hpp"

TE struct down {
  int N;
  vc<int> L;
  vc<ll> w;
  down(var g) : N(si(g)), L(N), w(N) {
    vc<int> q{0}, fa(N, -1);
    FOR(i, N) {
      int n = q[i];
      L[n] = i;
      for (Z &&e : g[n]) if (fa[e] == -1) fa[e] = n, w[e] = e.w, q.ep(e);
    }
  }
  ll operator()(int a, int b) { return L[a] > L[b] ? w[a] : w[b]; }
};

void Yorisou() {
  INT(N);
  LL(K);
  vc<vc<edge_w<ll>>> g(N);
  ll rs = inf<ll>;
  FOR(N - 1) {
    INT(a, b);
    LL(c);
    --a, --b;
    c -= K;
    g[a].ep(b, c), g[b].ep(a, c);
    chmin(rs, abs(c));
  }
  if (N == 1) return print(0);

  vc<int> d(N);
  vc<ll> dis(N);
  down<ll> ew(g);
  vc<PLL> st(ceil(N, 2));
  Z [fa, V] = dec_pr(g);
  dec1(fa, V, [&](var fa, var vs, int l, int r, int L, int R) {
    if (rs == 0) return;
    int n = si(vs);
    d.resize(n);
    dis.resize(n);
    d[0] = 0;
    dis[0] = 0;
    FOR(i, 1, n) {
      int f = fa[i], a = vs[f], b = vs[i];
      d[i] = d[f] + 1;
      dis[i] = dis[f] + ew(a, b);
    }
    if (r - l > R - L) swap(l, L), swap(r, R);
    Z ck = [&](ll x) -> bool {
      ++x;
      st.clear();
      FOR(i, l, r) {
        ll a = dis[i], b = d[i];
        st.ep(a - x * b, a + x * b);
      }
      sort(st);
      FOR(i, 1, si(st)) chmax(st[i].se, st[i - 1].se);
      FOR(i, L, R) {
        ll A = dis[i] - x * d[i], B = dis[i] + x * d[i];
        int p = lower_bound(all(st), -A, [](var p, ll x) { return p.fi < x; }) - bg(st);
        if (p and st[p - 1].se > -B) return 1;
      }
      return 0;
    };
    if (not ck(rs - 1)) return;
    rs = bina<0>(ck, rs - 1, -1);
  });
  print(rs);
}

int main() {
  Yorisou();
  return 0;
}