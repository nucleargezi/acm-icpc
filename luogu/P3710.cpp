#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/kdt/dyn_kdt_sayo.hpp"
#include "YRS/al/am/sum_affine.hpp"
#include "YRS/mod/mint_t.hpp"

using mint = M99;
struct dat {
  int o{}, l{}, r{}, d{};
};

void Yorisou() {
  INT(N, Q);
  vc<dat> a(Q + 1);
  vc<int> die(Q + 1, Q + 1), q;
  FOR(i, 1, Q + 1) {
    IN(a[i].o);
    if (a[i].o <= 2) {
      IN(a[i].l, a[i].r, a[i].d);
    } else {
      IN(a[i].l);
      if (a[i].o == 3) q.ep(i);
      else die[a[i].l] = i;
    }
  }

  dyn_kdt_sayo<2, Sum_affine<mint>, int> ds(si(q));
  for (int i : q) ds.ins({i, a[i].l}, 0);

  FOR(i, 1, Q + 1) if (a[i].o <= 2) {
    int d = a[i].d;
    pair<mint, mint> f;
    if (a[i].o == 1) f = {1, d};
    else f = {d, 0};
    ds.apply({i, a[i].l}, {die[i] - 1, a[i].r}, f);
  }
  ds.push_all();
  vc<mint> rs(Q + 1);
  FOR(i, 1, si(ds.pt)) rs[ds.pt[i].p[0]] = ds.pt[i].x;
  for (int i : q) print(rs[i]);
}

int main() {
  Yorisou();
  return 0;
}