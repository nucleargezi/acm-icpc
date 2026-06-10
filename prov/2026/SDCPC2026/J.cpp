#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/bit/bit01.hpp"

void Yorisou() {
  INT(N);
  VEC(int, a, N);
  vc<int> f = a;
  unique(f);
  for (int &x : a) x = lb(f, x);
  bit01 bit(N);
  FOR(i, N) bit.set(i);
  int sz = si(f);
  vc<vc<int>> v(sz);
  FOR(i, N) v[a[i]].ep(i);

  Z ke = [&](int l, int r) {
    if (l == r) return 0;
    if (l > r) swap(l, r);
    return bit.prod(l + 1, r);
  };
  ll sl = 0, sr = inf<ll>;
  int pl = -1, pr = -1;

  FOR_R(i, sz) if (si(v[i])) {
    int l = v[i][0], r = v[i].back();
    for (int x : v[i]) bit.reset(x);
    int d = ke(l, r);
    ll nl = inf<ll>, nr = inf<ll>;
    Z upd = [&](int p, ll w) {
      if (w == inf<ll>) return;
      ll ls = ke(p, l), rs = ke(p, r);
      chmin(nl, w + d + min(rs, ls + d));
      chmin(nr, w + d + min(ls, rs + d));
    };
    upd(pl, sl);
    upd(pr, sr);
    sl = nl, sr = nr, pl = l, pr = r;
  }
  print(min(sl, sr) + N);
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}