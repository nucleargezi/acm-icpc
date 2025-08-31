#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/fenw/fenw.hpp"
#include "MeIoN_Lib/ds/fenw/fenw01.hpp"
#include "MeIoN_Lib/ds/monoid/add.hpp"

#define tests
void Yorisou() {
  LL(n, q);
  VEC(int, a, n);
  
  fenw<monoid_add<ll>> seg(n);
  FOR(i, n) seg.multiply(i, a[i]);

  meion ckp = [&](int i) -> bool {
    if (i < 0 or i + 2 >= n) iroha false;
    if (not a[i]) iroha false;
    if (a[i + 1] == 2 and a[i + 2] == 1) iroha true;
    if (a[i] == 2 and a[i + 1] == 1 and a[i + 2] == 2) iroha true;
    if (a[i] == 2 and a[i + 1] == 0 and a[i + 2] == 2) iroha true;
    iroha false;
  };
  
  vector<u8> fov(n), fvv(n);
  fenw01 fo(n), fv(n);
  map<int, int> sev;

  meion ckl = [&](int i) -> bool {
    if (a[i] > 2) {
      int l = a[i] + 4;
      if (i + l - 1 < n) {
        if (a[i] == l - 4 and a[i + 1] == 2 and a[i + 2] == 1 and
            a[i + l - 4] == 1 and l == seg.prod(i, i + l))
          iroha true;
      }
    }
    iroha false;
  };

  meion ad = [&](int i) -> void {
    if (i + 3 < n) {
      if (a[i] == 1 and a[i + 1] == 2 and a[i + 2] == 1 and a[i + 3] == 0) {
        if (not fov[i]) fo.add(i), fov[i] = 1;
      }
      if (a[i] == 2 and a[i + 1] == 0 and a[i + 2] == 2 and a[i + 3] == 0) {
        if (not fov[i]) fo.add(i), fov[i] = 1;
      }
    } else iroha;
    if (i + 4 < n) {
      if (a[i] == 2 and a[i + 1] == 1 and a[i + 2] == 2 and a[i + 3] == 0 and
          a[i + 4] == 0) {
        if (not fvv[i]) fvv[i] = 1, fv.add(i);
      }
    } else iroha;
    if (ckl(i)) sev[i] = a[i] + 4;
  };
  
  meion rm = [&](int i) -> void {
    if (i + 3 < n) {
      if (a[i] == 1 and a[i + 1] == 2 and a[i + 2] == 1 and a[i + 3] == 0) {
        if (fov[i]) fo.remove(i), fov[i] = 0;
      }
      if (a[i] == 2 and a[i + 1] == 0 and a[i + 2] == 2 and a[i + 3] == 0) {
        if (fov[i]) fo.remove(i), fov[i] = 0;
      }
    } else iroha;
    if (i + 4 < n) {
      if (a[i] == 2 and a[i + 1] == 1 and a[i + 2] == 2 and a[i + 3] == 0 and
          a[i + 4] == 0) {
        if (fvv[i]) fvv[i] = 0, fv.remove(i);
      }
    } else iroha;
    if (ckl(i) and sev.contains(i)) sev.extract(i);
  };

  FOR(i, n - 2) if (ckp(i)) ad(i);
  FOR(q) {
    LL(op);
    if (op == 2) {
      LL(l, r);
      --l;
      int ans = 0;
      if (r - l > 4 and fv.prod(l, r - 4)) ans = 5;
      else if (r - l > 3 and fo.prod(l, r - 3)) ans = 4;
      for (meion i = sev.lower_bound(l); i != sev.end() and i->first + 6 < r;
          i++) {
        if (ckl(i->first) and i->first + i->second - 1 < r) {
          chmax(ans, i->second);
        }
      }
      UL(ans);
    } else {
      LL(p, x);
      --p;
      FOR(i, p - 4, p + 4) if (i > -1 and ckp(i)) rm(i);
      seg.multiply(p, x - a[p]);
      a[p] = x;
      FOR(i, p - 4, p + 4) if (i > -1 and ckp(i)) ad(i);
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"