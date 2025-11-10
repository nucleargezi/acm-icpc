#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/graph/Tree/tree_monoid.hpp"

// #define tests
using X = struct {
  ull a, b;
};
constexpr X op(X L, X R) {
  X ret{};
  ret.a = (L.a & R.a) | (~L.a & R.b);
  ret.b = (L.b & R.a) | (~L.b & R.b);
  return ret;
}
constexpr X make(int op, ull x) {
  X r{-1ull, 0};
  if (op == 1) r.a &= x, r.b &= x;
  if (op == 2) r.a |= x, r.b |= x;
  if (op == 3) r.a ^= x, r.b ^= x;
  return r;
}
struct mono {
  using X = ::X;
  static constexpr X op(X L, X R) { return ::op(L, R); }
  static constexpr X unit() { return {-1ull, 0}; }
  static constexpr bool commute = false;
};
void Yorisou() {
  INT(N, Q, K);
  graph g(N);
  vector<int> op(N);
  vector<ull> a(N);
  FOR(i, N) IN(op[i], a[i]);
  g.read_tree();
  tree v(g);
  tree_monoid<decltype(v), mono> seg(
      v, [&](int i) -> X { return make(op[i], a[i]); });
  FOR(Q) {
    INT(op, x, y);
    ull w;
    IN(w);
    if (op == 1) {
      --x, --y;
      Z [O, E] = seg.prod_path(x, y);
      ull r = 0;
      FOR_R(i, K) {
        bool x = O >> i & 1, y = E >> i & 1;
        if (y) {
          r |= 1ull << i;
        } else if (x) {
          if ((1ull << i) <= w) {
            r |= 1ull << i;
            w -= 1ull << i;
          } 
        }
      }
      print(r);
    } else {
      --x;
      seg.set(x, make(y, w));
    }
  }
}
#include "YRS/Z_H/main.hpp"