#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ttr/hld_sayo.hpp"

struct MX {
  struct X {
    ll s, d, sz;
  };

  struct A {
    ll kd, ksz, kc;
    bool operator==(const A &) const = default;
  };

  static constexpr bool commute = 1;

  static X unit() { return {0, 0, 0}; }

  static X op(const X &x, const X &y) {
    return {x.s + y.s, x.d + y.d, x.sz + y.sz};
  }

  static A id() { return {0, 0, 0}; }

  static A fu(const A &x, const A &y) {
    return {x.kd + y.kd, x.ksz + y.ksz, x.kc + y.kc};
  }

  static X map(const X &x, const A &f, ll len) {
    return {x.s + f.kd * x.d + f.ksz * x.sz + f.kc * len, x.d, x.sz};
  }
};
using X = MX::X;

void Yorisou() {
  INT(N);
  vc<vc<int>> g(N);
  FOR(N - 1) {
    INT(a, b);
    --a, --b;
    g[a].ep(b);
    g[b].ep(a);
  }
  hld<int> v(g, 0);
  vc<X> dat(N);
  FOR(x, N) dat[x] = {0, v.d[x], v.sz[x]};
  hld_sayo<int, MX> ds(v, dat);

  vc<ll> dps(N);
  FOR(i, N) dps[i] = v.d[v.V[i]];
  dps = pre_sum(dps);
  Z sbdps = [&](int x) -> ll { return dps[v.R[x]] - dps[v.L[x]]; };
  vc<ll> pdps(N);
  FOR(i, 1, N) {
    int x = v.V[i], f = v.fa[x];
    pdps[x] = pdps[f] + v.d[x];
  }

  ll tc = 0, td = 0;
  Z ad = [&](ll w) {
    tc += w * N, td += w * sbdps(0);
    ds.apply_sub(0, {0, w, 0});
  };

  Z ad_sb = [&](int x, ll w) {
    tc += w * v.sz[x], td += w * sbdps(x);
    if (v.fa[x] != -1) ds.apply(0, v.fa[x], {0, 0, w * v.sz[x]});
    ds.apply_sub(x, {0, w, 0});
  };

  Z ad_re = [&](int root, int x) {
    if (root == x) return ad(1);
    if (not v.ins(root, x)) return ad_sb(x, 1);
    ad(1), ad_sb(v.jump(x, root, 1), -1);
  };

  Z ad_pa = [&](int a, int b, ll w) {
    int c = v.lca(a, b);
    ll A = v.d[a] - v.d[c] + 1, B = v.d[b] - v.d[c] + 1;
    tc += w * (A + B - 1);
    td += w * (pdps[a] + pdps[b] - 2 * pdps[c] + v.d[c]);
    if (v.fa[c] != -1) ds.apply(0, v.fa[c], {0, 0, w * (A + B)});
    ds.apply(c, a, {-w, 0, w * (v.d[a] + 1)});
    ds.apply(c, b, {-w, 0, w * (v.d[b] + 1)});
    ds.apply(0, c, {0, 0, -w});
  };

  INT(Q);
  FOR(Q) {
    INT(op);

    if (op == 1) {
      INT(a, x);
      --a, --x;
      ad_re(a, x);
    } else if (op == 2) {
      INT(a, x);
      --a, --x;
      ad_pa(a, x, 1);
    } else {
      INT(x);
      --x;
      print(tc * v.d[x] + td - 2 * (ds.prod(0, x).s - ds.prod(0).s));
    }
  }
}

int main() {
  Yorisou();
  return 0;
}