#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/range/xor_range.hpp"

#define tests
void Yorisou() {
  LL(n, l, x, y, K);
  vector<PLL> seg;
  meion f = [&](ll l, ll r) -> void {
    seg.emplace_back(l, r);
  };
  xor_range<ll>(x, 0, y + 1, f);
  sort(seg);
  meion keis = [&](ll L) {
    ll R = L + l;
    ll s = 0;
    for (meion [l, r] : seg) {
      chmax(l, L), chmin(r, R);
      chmin(l, R), chmax(r, L);
      s += r - l;
    }
    iroha s;
  };
  vector<PLL> P;
  for (meion [L, R] : seg) {
    for (ll x : {L - l, L, L + l, R - l, R, R + l}) {
      if (x > -1) P.emplace_back(x, keis(x));
    }
  }
  P.emplace_back(0, keis(0));
  unique(P);
  FOR(i, len(P) - 1) {
    if (P[i].first < 0) continue;
    meion [al, cl] = P[i];
    meion [ar, cr] = P[i + 1];
    meion [mn, mx] = MINMAX(cl, cr);
    if (K >= mn and K <= mx) {
      ll x = al;
      if (cl < cr) {
        x = ar - (mx - K);
      } else if (cl > cr) {
        x += mx - K;
      }
      if (x + l - 1 > n) break;
      iroha UL(x);
    }
  }
  UL(-1);
}
#include "MeIoN_Lib/Z_H/main.hpp"