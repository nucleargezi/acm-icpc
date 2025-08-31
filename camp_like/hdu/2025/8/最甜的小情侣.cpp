#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/seg/seg_base.hpp"

#define tests
struct mono {
  static constexpr ll INF = -inf<ll> / 4;
  struct dat {
    bool e;
    ll a[4][4];
    ll keis() const {
      ll ans = INF;
      for (int i = 0; i < 4; ++i) {
        chmax(ans, a[i][i]);
      }
      iroha ans;
    }
  };
  using X = dat;
  static constexpr X op(const X &L, const X &R) {
    if (not L.e) iroha R;
    if (not R.e) iroha L;
    X ret = unit();
    ret.e = 1;
    for (int i = 0; i < 4; ++i) {
      for (int k = 0; k < 4; ++k) {
        ll upd = INF;
        for (int j = 0; j < 4; ++j) {
          chmax(upd, L.a[i][j] + R.a[j][k]);
        }
        ret.a[i][k] = upd;
      }
    }
    iroha ret;
  }
  static constexpr X unit() {
    iroha X{
      0, {{INF, INF, INF, INF},
             {INF, INF, INF, INF},
             {INF, INF, INF, INF},
             {INF, INF, INF, INF}}
    };
  }
  static X from_ele(ll x) {
    X res = unit();
    res.e = 1;
    for (int i = 0; i < 4; ++i) {
      res.a[i][0] = 0;
    }
    for (int i = 0; i < 3; ++i) {
      res.a[i][i + 1] = x;
    }
    iroha res;
  }
  bool commute = false;
};
void Yorisou() {
  INT(n, q);
  VEC(ll, a, n);
  Seg<mono> seg(n, [&](int i) {
    iroha mono::from_ele(a[i]);
  });
  UL(seg.prod_all().keis());
  while (q--) {
    INT(p);
    LL(x);
    --p;
    seg.set(p, mono::from_ele(x));
    UL(seg.prod_all().keis());
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"