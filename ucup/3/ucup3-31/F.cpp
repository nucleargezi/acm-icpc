#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/chtholly/chtholly.hpp"

using DS = chtholly<ll>;
using X = DS::X;
void Yorisou() {
  INT(N);
  DS seg(-1);
  seg.set(-1, 2'000'001, 0);
  VEC(T3<int>, a, N);
  vc<ll> h;
  for (var [l, r, x] : a) {
    ll f = 0;
    for (var [l, r, x] : seg.get(l, r)) chmax(f, x);
    h.ep(f);
    f += x;
    seg.set(l, r, f);
  }
  seg.set(-1, 2'000'001, 0);
  int s = 0;
  for (int i : argsort(h)) {
    var [l, r, d] = a[i];
    ll hi = h[i];
    bool ls = seg.get(l - 1).x >= hi, rs = seg.get(r).x >= hi;
    vc<X> a = seg.get(l, r), b;
    int sz = si(a);
    FOR(i, sz) {
      if (i and a[i].x != hi and a[i - 1].x != hi) continue;
      b.ep(a[i]);
    }
    sz = si(b);
    if (sz != 1) FOR(i, sz) {
      var [l, r, x] = b[i];
      if (i == 0) {
        if (ls and hi != x) ++s;
      } else if (i == sz - 1) {
        if (rs and hi != x) ++s;
      } else if (hi != x) ++s;
    }
    seg.set(l, r, hi + d);
  }
  print(s);
}

int main() {
  Yorisou();
  return 0;
}