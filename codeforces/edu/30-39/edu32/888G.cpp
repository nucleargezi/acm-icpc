#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/trie_bina.hpp"

using DS = trie_bina<30, 0, int, int, 1 << 12>;
using np = DS::np;
void Yorisou() {
  INT(N);
  VEC(int, a, N);
  DS tr;
  np t = 0;
  ll s = 0;
  Z f = [&](Z &f, const vc<int> &a, int d) -> void {
    if (a.empty()) return;
    if (QMIN(a) == QMAX(a)) return;
    vc<int> l, r;
    for (int x : a) {
      if (x >> d & 1) l.ep(x ^ (1 << d));
      else r.ep(x);
    }
    f(f, l, d - 1);
    f(f, r, d - 1);
    if (si(l) and si(r)) {
      s += 1 << d;
      tr.a.reset();
      t = 0;
      for (int x : l) t = tr.add(t, x);
      int mx = inf<int>;
      for (int x : r) chmin(mx, tr.min(t, x));
      s += mx;
    }
  };
  f(f, a, 29);
  print(s);
}

int main() {
  Yorisou();
  return 0;
}