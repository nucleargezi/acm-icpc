#include "YRS/all.hpp"
#include "YRS/ds/rollback/rollback_dsu.hpp"

void before() {}

// #define tests
using dsu = rollback_dsu;
void Yorisou() {
  INT(n, m);
  map<PII, int> M;
  vc<T4<int>> go;
  vc<vc<PII>> q(m);
  FOR(i, m) {
    INT(op, x, y);
    --x, --y;
    if (x > y) swap(x, y);
    if (op == 0) {
      M[{x, y}] = i;
    } else if (op == 1) {
      go.ep(M[{x, y}], i, x, y);
      M.extract({x, y});
    } else {
      q[i].ep(x, y);
    }
  }
  for (Z [p, l] : M) {
    go.ep(l, m, p.fi, p.se);
  }
  vc<int> I(len(go));
  iota(I.begin(), I.end(), 0);
  dsu fa(n);
  Z f = [&](Z &f, int l, int r, const vc<int> &I) -> void {
    if (l > r - 1) return;
    int t{fa.time()};
    int m = (l + r) >> 1;
    vc<int> L, R;
    for (int id : I) {
      Z [pl, pr, x, y] = go[id];
      if (pl < l + 1 and pr > r - 1) {
        fa.merge(x, y);
      } else {
        if (pl < m) L.ep(id);
        if (pr > m) R.ep(id);
      }
    }
    if (l == r - 1) {
      for (Z [x, y] : q[l]) {
        print(fa[x] == fa[y] ? 'Y' : 'N');
        cout.flush();
      }
    } else {
      f(f, l, m, L), f(f, m, r, R);
    }
    fa.rollback(t);
  };
  f(f, 0, m, I);
}