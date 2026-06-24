#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/sam.hpp"
#include "YRS/ds/seg/segd_t.hpp"

int K;
struct MX {
  struct X {
    vc<int> l, r;
    int s;
  };

  static X op(const X &a, const X &b) {
    X c;
    c.s = min(a.s, b.s);

    int nl = min(K, int(a.l.size() + b.l.size()));
    c.l.reserve(nl);
    for (int x : a.l) {
      c.l.ep(x);
      if (si(c.l) == K) break;
    }
    if (si(c.l) < K) {
      for (int x : b.l) {
        c.l.ep(x);
        if (si(c.l) == K) break;
      }
    }

    int nr = min(K, int(a.r.size() + b.r.size()));
    c.r.reserve(nr);
    for (int x : b.r) {
      c.r.ep(x);
      if (si(c.r) == K) break;
    }
    if (si(c.r) < K) {
      for (int x : a.r) {
        c.r.ep(x);
        if (si(c.r) == K) break;
      }
    }
    int n = si(a.r), m = si(b.l);
    int L = max(1, K - m), R = min(K - 1, n);
    FOR(i, L, R + 1) {
      int rs = K - i, l = a.r[i - 1], r = b.l[rs - 1];
      chmin(c.s, r - l);
    }
    return c;
  }

  static X unit() {
    return {{}, {}, inf<int>};
  }

  static X sing(int i) {
    X c = unit();
    c.l.ep(i);
    c.r.ep(i);
    return c;
  }
  
  static constexpr bool commute = 0;
};

using DS = segd_t<MX, 0, int, 20>;
using np = DS::np;
void Yorisou() {
  INT(N);
  IN(K);
  STR(s);
  if (K == 1) return print(0);
  FOR(i, N) s[i] -= 'a';
  int sz;
  Z [en, le, fa, V] = [&]() {
    sam ss;
    ss.build(s);
    sz = si(ss);
    vc<int> le(sz), fa(sz), V;
    FOR(i, 1, sz) le[i] = ss[i].sz;
    FOR(i, 1, sz) fa[i] = ss[i].fa;
    vc<vc<int>> g = ss.build_dir_g();
    Z f = [&](Z &f, int n) -> void {
      if (n) V.ep(n);
      for (int x : g[n]) f(f, x);
    };
    f(f, 0);
    return tuple{ss.en, le, fa, V};
  }();

  DS seg(0, N);
  vc<np> t(sz);
  FOR(i, N) {
    np &x = t[en[i]];
    x = seg.set(x, i, MX::sing(i));
  }
  int rs = 0;
  reverse(V);
  for (int n : V) {
    int sz = seg.prod(t[n]).s;
    if (sz != inf<int>) chmax(rs, le[n] * K - (sz + le[n]));
    if (fa[n]) t[fa[n]] = seg.merge_to(t[fa[n]], t[n]);
  }
  print(rs);
}

int main() {
  Yorisou();
  return 0;
}