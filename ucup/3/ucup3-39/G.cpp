#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/seg/seg_dual_t.hpp"
#include "YRS/al/m/min.hpp"
#include "YRS/ge/basic/point.hpp"

using P = point<ll>;
using DS = seg_dual_t<Min<PII>>;
void yorisou() {
  INT(N);
  map<int, int> mp;
  FOR(N) {
    INT(x, y);
    chmax(mp[x], y);
  }
  vc<P> a;
  for (var [x, y] : mp) a.ep(x, y);
  N = si(a);
  int mx = -1;
  FOR_R(i, N) {
    var [x, y] = a[i];
    if (chmax(mx, y)) a.ep(x, y);
  }
  a.erase(bg(a), bg(a) + N);
  reverse(all(a));
  N = si(a);

  vc<char> vis(N);
  vc<int> s;
  FOR(i, N) {
    while (si(s) > 1) {
      int l = s.ed()[-2], m = s.ed()[-1];
      if (ccw(a[l], a[m], a[i]) == 1) pop(s);
      else break;
    }
    s.ep(i);
  }
  for (int x : s) vis[x] = 1;
  vc<int> L(N), R(N);
  FOR(i, N) {
    if (vis[i]) L[i] = i;
    else L[i] = L[i - 1];
  }
  FOR_R(i, N) {
    if (vis[i]) R[i] = i;
    else R[i] = R[i + 1];
  }

  vc<vc<PII>> rgs(N);
  FOR(i, N) if (not vis[i]) {
    int l = L[i], r = R[i];
    int d = bina([&](int d) -> bool {
      P tmp = a[i];
      tmp.x += d;
      return ccw(a[l], tmp, a[r]) != -1;
    }, 0, a[r].x - a[i].x);
    int rx = a[i].x + d;
    rgs[l].ep(i, bina([&](int p) { return rx >= a[p].x; }, i, N) + 1);
  }

  int co = SUM<int>(vis), op = 0;
  DS seg(N);
  FOR(i, N) if (si(rgs[i])) {
    Z &v = rgs[i];
    seg.apply(i, i + 1, {0, 0});
    for (var [ls, rs] : v) {
      Z [a, b] = seg.get(ls - 1);
      seg.apply(ls, ls + 1, {a + 1, b});
      seg.apply(ls, rs, {a + 1, b + 1});
    }
    var [a, b] = seg.get(R[i + 1] - 1);
    co += a, op += b;
  }
  print(co);
  print(op);
}

int main() {
  yorisou();
  return 0;
}