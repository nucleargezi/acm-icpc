#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
#include "YRS/ds/lct/lct_act.hpp"
#include "YRS/ds/lct/lct_monoid.hpp"

// #define tests
struct MX {
  using X = int;
  static constexpr X op(X a, X b) { return a + b; }
  static constexpr X unit() { return 0; }
};
struct MA {
  using X = int;
  static constexpr X op(X a, X b) { return b == -1 ? a : b;; }
  static constexpr X unit() { return -1; }
};
struct AM {
  using MX = ::MX;
  using MA = ::MA;
  using X = MX::X;
  using A = MA::X;
  static constexpr X act(X x, A a, int sz) { return a == -1 ? x : a * sz; }
};
void Yorisou() {
  INT(N, Q);
  LCT_act_commute<AM> A(N << 1);
  LCT_monoid_commute<MX> B(N << 1);
  int ans = 0, Ta = N, Tb = N;
  FOR(i, N, N << 1) A.a[i].mx = 1;
  FOR(i, N) B.a[i].mx = 1;
  FOR(Q) {
    INT(op, x, y);
    x ^= ans, y ^= ans;
    --x, --y;
    if (op == 1) {
      if (A.get_rt(x) == A.get_rt(y)) {
        A.apply(x, y, 0);
        vector<int> pa;
        B.evert(x);
        while (y != x) {
          pa.ep(y);
          y = B.get_fa(y);
        }
        pa.ep(y);
        const int sz = len(pa);
        FOR(i, 1, sz) B.cut(pa[i - 1], pa[i]);
        for (int x : pa) B.link(x, Tb);
        ++Tb;
      } else {
        A.link(x, Ta), A.link(y, Ta);
        ++Ta;
        B.link(x, y);
      }
    } else if (op == 2) {
      print(A.get_rt(x) == A.get_rt(y) ? ans = A.prod(x, y) : -1);
    } else if (op == 3) {
      print(A.get_rt(x) == A.get_rt(y) ? ans = B.prod(x, y) : -1);
    }
  }
}
#include "YRS/Z_H/main.hpp"