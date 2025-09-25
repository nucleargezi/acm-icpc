#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/ds/seg/seg_base.hpp"

// #define tests
struct mono {
  using X = struct {
    int ans;
    int l, r, sz;
    bool lc, rc, e;
  };

  static constexpr X op(const X &L, const X &R) {
    if (L.e) return R;
    if (R.e) return L;
    X res = {};
    res.sz = L.sz + R.sz;
    res.lc = L.lc, res.rc = R.rc;
    res.l = L.l;
    if (L.rc != R.lc and L.ans == L.sz) res.l = L.sz + R.l;
    res.r = R.r;
    if (R.lc != L.rc and R.ans == R.sz) res.r = R.sz + L.r;
    res.ans = std::max({L.ans, R.ans, res.l, res.r});
    if (L.rc != R.lc) chmax(res.ans, L.r + R.l);
    return res;
  }

  static constexpr X unit() {
    return {0, 0, 0, 0, 0, 0, 1};
  }

  static constexpr X fromele(bool x) {
    return {1, 1, 1, 1, x, x, 0};
  }
};
using X = mono::X;
void Yorisou() {
  INT(N, Q);
  vector<int> a(N);
  Seg<mono> seg(N, [&](int i) -> X { return mono::fromele(a[i]); });
  FOR(Q) {
    INT(x);
    --x;
    a[x] ^= 1;
    seg.set(x, mono::fromele(a[x]));
    print(seg.prod_all().ans);
  }
}
#include "YRS/Z_H/main.hpp"