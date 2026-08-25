#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/sam.hpp"
#include "YRS/ttr/hld_sayo.hpp"

struct MX {
  using X = PLL;
  using A = ll;
  static X op(const X &a, const X &b) { return {a.fi + b.fi, a.se + b.se}; }
  static X unit() { return {}; }
  static A fu(const A &a, const A &b) { return a + b; }
  static A id() { return 0; }
  static X map(X x, const A &a, ll) {
    x.fi += x.se * a;
    return x;
  }
};

void Yorisou() {
  INT(N, Q);
  STR(s);
  for (char &c : s) c -= 'a';
  VEC(ll, a, N);
  reverse(s);
  reverse(a);

  sam ss(N);
  ss.build(s);
  Z ps = std::move(ss.en);
  int M = si(ss);
  vc<vc<int>> g(M);
  FOR(i, 1, M) {
    g[ss[i].fa].ep(i);
    g[i].ep(ss[i].fa);
  }
  hld v(g, 0);
  var fa = v.fa, &hd = v.hd, &L = v.L, &R = v.R, &V = v.V;

  vc<ll> pr(M);
  FOR(i, N) pr[L[ps[i]]] += a[i];
  pr = pre_sum(pr);

  vc<int> w(M);
  vc<PLL> b(M);
  FOR(i, 1, M) {
    w[i] = ss[i].sz - ss[fa[i]].sz;
    ll x = pr[R[i]] - pr[L[i]];
    b[L[i]] = {x * w[i], w[i]};
  }
  segl_t<MX> seg(b);

  Z apply = [&](int x, ll a) {
    while (hd[x] != 0) {
      seg.apply(L[hd[x]], L[x] + 1, a);
      x = fa[hd[x]];
    }
    seg.apply(0, L[x] + 1, a);
  };

  Z path = [&](int x) {
    ll s = 0;
    while (hd[x] != 0) s += seg.prod(L[hd[x]], L[x] + 1).fi, x = fa[hd[x]];
    return s + seg.prod(0, L[x] + 1).fi;
  };

  Z find = [&](int x, int m) {
    return v.max_hi(x, [&](int x) { return ss[x].sz >= m; });
  };

  Z prod = [&](int x, int m) {
    int y = find(x, m);
    ll k = seg.get(L[y]).fi / w[y];
    return path(y) - k * (ss[y].sz - m);
  };

  FOR(Q) {
    INT(op);
    if (op == 1) {
      INT(i);
      LL(x);
      i = N - i;
      apply(ps[i], x - a[i]);
      a[i] = x;
    } else if (op == 2) {
      INT(p, m);
      print(prod(ps[N - p], m));
    } else {
      INT(i, m);
      LL(k);
      int y = find(ps[N - i], m);
      if (prod(ps[N - i], m) < k) {
        print(0);
        continue;
      }
      static vc<PII> st;
      st.clear();
      int x = y;
      while (hd[x] != 0) st.ep(L[hd[x]], L[x] + 1), x = fa[hd[x]];
      st.ep(0, L[x] + 1);
      reverse(st);
      for (var [l, r] : st) {
        ll s = seg.prod(l, r).fi;
        if (k > s) {
          k -= s;
          continue;
        }
        int p = seg.maxr([&](PLL x) { return x.fi < k; }, l);
        k -= seg.prod(l, p).fi;
        int e = V[p];
        ll h = seg.get(p).fi / w[e];
        print(ss[fa[e]].sz + ceil(k, h));
        break;
      }
    }
  }
}

int main() {
  Yorisou();
  return 0;
}