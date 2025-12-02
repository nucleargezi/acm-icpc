#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
// #include "YRS/ds/seg/dynamic_seg.hpp"
#include "YRS/ds/seg/dynamic_seg.hpp"

#define tests 0
#define fl 0
#define DB 10
struct MX {
  using X = struct {
    int l, r, x;
  };
  static constexpr X unit() { return {-1, -1, 0}; }
  static constexpr X op(const X &L, const X &R) {
    if (L.l == -1) return R;
    if (R.l == -1) return L;
    return {L.l, R.r, L.x + R.x - (L.r == R.l)};
  }
  static constexpr bool commute = false;
};
using DS = dynamic_seg<MX, 0, int, 1 << 19>;
using np = DS::np;
void Yorisou() {
  INT(N, Q);
  VEC(int, a, N);
  FOR(i, N) --a[i];
  DS seg(0, N);
  vc<np> r(1'000'000);
  FOR(i, 1'000'000) r[i] = seg.newnode();
  FOR(i, N) {
    int x = a[i];
    r[x] = seg.multiply(r[x], i, {i, i + 1, 1});
  }
  int s = 0;
  FOR(i, 1'000'000) s += seg.prod(r[i], 0, N).x;
  FOR(Q) {
    INT(op);
    if (op == 1) {
      INT(x, y);
      --x, --y;
      if (x == y) continue;
      s -= seg.prod(r[x], 0, N).x;
      s -= seg.prod(r[y], 0, N).x;
      r[y] = seg.merge_to(r[y], r[x], MX::op);
      r[x] = nullptr;
      s += seg.prod(r[y], 0, N).x;
    } else {
      print(s);
    }
  }
}
#include "YRS/Z_H/main.hpp"