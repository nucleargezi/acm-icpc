#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/ds/lct/lct_monoid.hpp"

// #define tests
constexpr int sz = 11;
using RE = double;
using X = array<RE, sz>;
struct fac {
  ll a[sz]{1};
  constexpr fac() { FOR(i, 1, sz) a[i] = a[i - 1] * i; }
  constexpr ll operator[](int i) const { return a[i]; }
} constexpr fac;
struct MX {
  using X = ::X;
  static constexpr X unit() { return {}; }
  static constexpr X make(int op, RE a, RE b) {
    X r{};
    if (op == 1) {
      RE t = 1, s = std::sin(b), c = std::cos(b);
      FOR(i, sz) {
        r[i] = t / fac[i] * ((i & 1) ? c : s) * ((i % 4 < 2) ? 1 : -1);
        t *= a;
      }
    } else if (op == 2) {
      RE t = 1, bs = std::exp(b);
      FOR(i, sz) {
        r[i] = t / fac[i] * bs;
        t *= a;
      }
    } else {
      r[0] = b, r[1] = a;
    }
    return r;
  }
  static constexpr X op(const X &L, const X &R) {
    X r{};
    FOR(i, sz) r[i] = L[i] + R[i];
    return r;
  }
  static constexpr bool commute = true;
};
using LCT = LCT_monoid_commute<MX>;
void Yorisou() {
  cout << std::fixed << std::setprecision(8);
  INT(N, Q);
  STR(type);
  LCT lct(N);
  FOR(i, N) {
    INT(op);
    REAL(a, b);
    lct.a[i].mx = MX::make(op, a, b);
  }
  FOR(Q) {
    STR(op);
    if (op[0] == 'a') {
      INT(x, y);
      lct.link(x, y);
    } else if (op[0] == 'd') {
      INT(x, y);
      lct.cut(x, y);
    } else if (op[0] == 'm') {
      INT(x, op);
      REAL(a, b);
      lct.set(x, MX::make(op, a, b));
    } else {
      INT(x, y);
      REAL(bs);
      if (lct.get_rt(x) == lct.get_rt(y)) {
        Z poly = lct.prod(x, y);
        RE ans = 0, x = 1;
        FOR(i, sz) {
          ans += x * poly[i];
          x *= bs;
        }
        print(ans);
      } else {
        print("unreachable");
      }
    }
  }
}
#include "YRS/Z_H/main.hpp"