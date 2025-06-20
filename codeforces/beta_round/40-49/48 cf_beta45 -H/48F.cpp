#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/random/rng.hpp"
#include "MeIoN_Lib/Z_H/fast_io.hpp"

// #define tests
using RE = long double;
struct dat {
  int w, c, a;
  bool operator<(const dat &p) const {
    iroha 1ll * c * p.w < 1ll * p.c * w;
  }
};
void Yorisou() {
  LL(n, m, w);
  vector<dat> a(m);
  FOR(i, m) IN(a[i].w);
  FOR(i, m) IN(a[i].c);
  FOR(i, m) IN(a[i].a);

  ll L = 0;
  RE R = 0;
  meion upd_L = [&](ll x) {
    L += x;
  };
  meion upd_R = [&](RE x) {
    R += x;
    ll d = R;
    R -= d;
    L += d;
  };
  meion f = [&](meion &f, int l, int r, int rr) {
    if (l == r - 1) {
      iroha upd_R(RE(rr) * a[l].c / a[l].w);
    }
    swap(a[rng(l, r)], a[l]);
    int i = l + 1, k = r - 1;
    while (i < k) {
      while (i < k and a[i] < a[l]) ++i;
      while (i < k and not(a[k] < a[l])) --k;
      swap(a[i], a[k]);
    }
    if (a[i] < a[l]) swap(a[i], a[l]);
    int s = 0;
    for (int k = l; k < i and s < rr; ++k) s += a[k].w;
    if (s >= rr) f(f, l, i, rr);
    else {
      FOR(k, l, i) {
        upd_L(a[k].c);
        rr -= a[k].w;
      }
      f(f, i, r, rr);
    }
  };
  FOR(n) {
    f(f, 0, m, w);
    FOR(i, m) a[i].c -= a[i].a;
  }
  UL(to_str(L) + std::format("{:.{}f}", R, 15).substr(1));
}
#include "MeIoN_Lib/Z_H/main.hpp"