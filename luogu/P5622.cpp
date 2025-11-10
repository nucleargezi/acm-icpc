#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
#include "YRS/ds/lct/lct_act.hpp"

// #define tests
using X = ll;
struct MX {
  using X = ll;
  static constexpr X op(X a, X b) { return a + b; }
  static constexpr X unit() { return 0; }
};
using A = bool;
struct MA {
  using X = A;
  static constexpr X op(X a, X b) { return b ? b : a; }
  static constexpr X unit() { return 0; }
};
struct AM {
  using MX = ::MX;
  using MA = ::MA;
  using X = MX::X;
  using A = MA::X;
  static constexpr X act(X x, A f, int) { return f ? 0 : x; }
};
using LCT = LCT_act_commute<AM>;
ull ans = 0;
int N, Q;
void make(int &x) {
  x ^= ans % N;
  if (x > N) x %= N;
  if (not x) x = 1;
}
void Yorisou() {
  IN(N, Q);
  LCT lct(N << 1);
  int t = N;
  FOR(Q) {
    INT(op, x, y);
    make(x), make(y);
    if (op == 1) {
      --x, --y;
      if (lct.get_rt(x) == lct.get_rt(y)) {
        vector<int> pa;
        lct.evert(x);
        while (x != y) {
          pa.ep(y);
          y = lct.get_fa(y);
        }
        pa.ep(x);
        const int sz = len(pa);
        FOR(i, 1, sz) lct.cut(pa[i - 1], pa[i]);
        for (int x : pa) lct.link(x, t);
        ++t;
      } else {
        lct.link(x, y);
      }
    } else if (op == 2) {
      --x;
      lct.multiply(x, y);
    } else {
      --x, --y;
      if (lct.get_rt(x) == lct.get_rt(y)) {
        print(ans = lct.prod(x, y));
        lct.apply(x, y, 1);
      } else {
        print(ans = 0);
      }
    }
  }
}
#include "YRS/Z_H/main.hpp"