#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/gg/unicycle.hpp"
#include "YRS/ttr/hld_sayo.hpp"

struct sayo {
  using X = PII;
  using A = char;
  static X op(const X &a, const X &b) { return {a.fi + b.fi, a.se + b.se}; }
  static X unit() { return {}; }
  static A fu(A a, A b) { return a ^ b; }
  static A id() { return 0; }
  static X map(const X &a, A f, ll) {
    if (f) return {a.se, a.fi};
    return a;
  }
  static constexpr bool commute = 1;
};

void Yorisou() {
  INT(N, Q);
  vc<vc<edge_id>> g(N);
  FOR(i, N) {
    INT(a, b);
    --a, --b;
    g[a].ep(b, i);
    g[b].ep(a, i);
  }

  unicycle gg(g);
  Z &v = gg.v;
  Z &fa = gg.fa, &cc = gg.cc;
  int r = gg.r, sz = si(cc);
  vc<int> I(N);
  for (int t = 0; int x : cc) I[x] = t++;
  hld_sayo<edge_id, sayo> seg(v);
  FOR(i, N) if (i != v.rt) seg.set(i, {1, 0});

  bool ov = 1;
  FOR(Q) {
    INT(a, b);
    --a, --b;
    if (not gg.vis[v.lca(a, b)]) {
      seg.apply(a, b, 1, 1);
    } else {
      int c = fa[r], aa = v.lca(a, c), bb = v.lca(b, c);
      seg.apply(a, aa, 1, 1);
      seg.apply(b, bb, 1, 1);
      if (2 * abs(I[bb] - I[aa]) == sz) {
        int l = cc[(I[aa] - 1 + sz) % sz], r = cc[(I[aa] + 1) % sz];
        if (I[aa] < I[bb]) swap(l, r);
        if (l < r) {
          seg.apply(aa, bb, 1, 1);
        } else {
          seg.apply(cc[0], aa, 1, 1);
          seg.apply(bb, cc[sz - 1], 1, 1);
          ov ^= 1;
        }
      } else {
        if (abs(I[aa] - I[bb]) * 2 < sz) {
          seg.apply(aa, bb, 1, 1);
        } else {
          if (I[aa] > I[bb]) swap(aa, bb);
          seg.apply(cc[0], aa, 1, 1);
          seg.apply(bb, cc[sz - 1], 1, 1);
          ov ^= 1;
        }
      }
    }
    Z [s, _0] = seg.prod();
    Z [c, _1] = seg.prod(cc[0], cc[sz - 1], 1);
    if (c == sz and ov) --s;
    if (not c and not ov) ++s;
    print(s + ov);
  }
}

int main() {
  Yorisou();
  return 0;
}