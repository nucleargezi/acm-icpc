#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/tr/hld.hpp"
#include "YRS/ds/seg/segdl_t.hpp"
#include "YRS/al/am/sum_affine.hpp"

using DS = segdl_t<Sum_affine<int>>;
using np = DS::np;
ull hs(const string &s) {
  ull g = 0;
  for (ull c : s) g = (u128(g) * 131 + c) % ((1ull << 61) - 1);
  return g;
}
void Yorisou() {
  INT(N, Q);
  graph g(N);
  g.sc();
  hld v(g);

  vc<vc<ull>> a(N);
  vc<ull> f;
  FOR(i, N) {
    INT(sz);
    FOR(sz) {
      STR(s);
      a[i].ep(hs(s));
    }
    for (var x : a[i]) f.ep(x);
  }
  unique(f);
  for (Z &a : a) for (Z &x : a) x = lb(f, x);

  int M = si(f);
  vc<np> t(M);
  DS seg(0, N);
  FOR(i, N) {
    int idx = v.L[i];
    for (int x : a[i]) t[x] = seg.multiply(t[x], idx, 1);
  }

  FOR(Q) {
    STR(op, p);
    if (op[0] == 'q' and p == "/p") {
      INT(a, b);
      --a, --b;
      print(v.dist(a, b));
    } else if (op[0] == 'q' and p == "/e") {
      INT(a, b);
      --a, --b;
      STR(suf);
      suf.erase(0, 2);
      int hsh = hs(suf), s = 0;
      if (binary_search(all(f), hsh)) {
        int i = lb(f, hs(suf));
        for (Z [l, r] : v.dec(a, b, 0)) {
          if (l > r) swap(l, r);
          s += seg.prod(t[i], l, r + 1);
        }
      }
      print(s);
    } else {
      INT(a, b);
      --a, --b;
      STR(suf);
      suf.erase(0, 2);
      int hsh = hs(suf), s = 0;
      if (binary_search(all(f), hsh)) {
        int i = lb(f, hs(suf));
        for (Z [l, r] : v.dec(a, b, 0)) {
          if (l > r) swap(l, r);
          s += seg.prod(t[i], l, r + 1);
          t[i] = seg.apply(t[i], l, r + 1, {0, 0});
        }
      }
      print(s);
    }
  }
}

int main() {
  Yorisou();
  return 0;
}