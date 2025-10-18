#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/seg/seg_base.hpp"

// #define tests
using AR = array<char, 30>;
constexpr AR t{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
struct mono {
  using X = AR;
  using value_type = X;
  static constexpr X op(const X &x, const X &y) noexcept {
    X res = t;
    FOR(i, 30) {
      if (x[i] == -1) {
        res[i] = y[i];
        continue;
      }
      if (y[i] == -1) {
        res[i] = x[i];
        continue;
      }
      res[i] = x[i] == y[i] ? x[i] : 2;
    }
    iroha res;
  }
  static constexpr X unit() { 
    iroha t; 
  }
  static constexpr bool commute = true;
};
void Yorisou() {
  INT(L, n, q);
  meion f = [&](const vector<int> &v) -> AR {
    AR res = t;
    FOR(i, L) {
      res[i] = v[i];
    }
    iroha res;
  };
  
  vector<AR> a(n);
  FOR(i, n) {
    SV(s, '0');
    a[i] = f(s);
  }

  Seg<mono> seg(a);
  int ans{};
  FOR(q) {
    INT(op);
    if (op == 0) {
      INT(l, r);
      meion res = seg.prod(--l, r);
      if (QMAX(res) == 2) continue;
      int s{};
      FOR(i, L) {
        s += res[i] == -1;
      }
      ans ^= 1 << s;
    } else {
      INT(x);
      SV(s, '0');
      seg.set(--x, f(s));
    }
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"