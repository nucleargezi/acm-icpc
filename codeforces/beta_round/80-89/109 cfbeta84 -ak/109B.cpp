#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

using re = ld;
void Yorisou() {
  INT(pl, pr, ql, qr, k);
  vc<ll> a;
  FOR(sz, 1, 11) {
    string n(sz, ' ');
    FOR(s, 1 << sz) {
      FOR(k, sz) {
        if (s >> k & 1) n[k] = '4';
        else n[k] = '7';
      }
      a.ep(stoll(n));
    }
  }
  sort(a);
  int sz = si(a);
  Z ke = [&](ll l, ll r, PLL g) -> ll {
    Z [lp, rp] = g;
    if (rp < l or lp > r) return 0;
    chmax(lp, l);
    chmin(rp, r);
    return rp - lp + 1;
  };
  ll s = 0;
  FOR(i, sz - k + 1) {
    PLL lg, rg;
    lg = {i ? a[i - 1] + 1 : 0, a[i]};
    rg = {a[i + k - 1], i + k < sz ? a[i + k] - 1 : inf<int> * 1'0000};
    s += ke(pl, pr, lg) * ke(ql, qr, rg);
    s += ke(pl, pr, rg) * ke(ql, qr, lg);
    if (k == 1) s -= ke(pl, pr, {a[i], a[i]}) * ke(ql, qr, {a[i], a[i]});
  }
  print(re(s) / (ll(pr - pl + 1) * (qr - ql + 1)));
}

int main() {
  Yorisou();
  return 0;
}