#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  LL(tl, tr, xl, xr, lo);
  vc<ll> f(xl + 1, -1);
  f[0] = xr;
  FOR(yl, 1, xl + 1) {
    if (tl * yl + tr * xr < lo * (yl + xr)) continue;
    f[yl] = bina([&](ll yr) -> bool {
      return tl * yl + tr * yr >= lo * (yl + yr);
    }, xr, -1);
  }
  if (tl >= lo and tl == tr) fill(all(f), xr);
  PLL fr{-1, -1}, rs{-1, -1};
  FOR(yl, xl + 1) if (f[yl] != -1) {
    ll yr = f[yl];
    PLL t = {tl * yl + tr * yr, yl + yr};
    if (fr.fi == -1 or fr.fi * t.se > fr.se * t.fi or
        (fr.fi * t.se == fr.se * t.fi and rs.fi + rs.se < yl + yr)) {
      fr = t, rs = {yl, yr};
    }
  }
  print(rs);
}

int main() {
  Yorisou();
  return 0;
}