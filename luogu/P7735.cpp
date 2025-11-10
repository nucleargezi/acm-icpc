#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/ds/lct/lct_act.hpp"

#define tests
using X = struct {
  int l, r, c;
};
struct MX {
  using X = ::X;
  static constexpr X unit() { return {}; }
  static constexpr X op(X L, X R) {
    if (L.l == -1) return R;
    if (R.r == -1) return L;
    return {L.l, R.r, L.c + R.c + (L.r == R.l)};
  }
};
constexpr X make(int x) { return {x, x, 0}; }
using A = int;
struct MA {
  using X = ::A;
  static constexpr X unit() { return -1; }
  static constexpr X op(X L, X R) {
    if (R != -1) return R;
    return L;
  }
};
struct AM {
  using MX = ::MX;
  using MA = ::MA;
  using X = MX::X;
  using A = MA::X;
  static constexpr X act(X x, A a, int sz) {
    if (a != -1) return {a, a, sz - 1};
    return x;
  }
};
using LCT = LCT_act<AM>;
void Yorisou() {
  INT(N, Q);
  LCT lct(N);
  FOR(i, N) lct.a[i].mx = make(N + Q - i);
  FOR(i, N - 1) {
    INT(x, y);
    --x, --y;
    lct.link(x, y);
  }
  FOR(i, Q) {
    INT(op, x, y);
    --x, --y;
    if (op == 1) lct.apply(x, y, i);
    else print(lct.prod(x, y).c);
  }
}
#include "YRS/Z_H/main.hpp"