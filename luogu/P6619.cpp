#define YRSD
#include "YRS/all.hpp"
#include "YRS/IO/fast_io.hpp"
#include "YRS/ds/seg/seg_t.hpp"
#include "YRS/al/m/add_array.hpp"

using A = array<int, 2>;
using DS = seg_t<monoid_add_arr<int, 2>>;
void Yorisou() {
  INT(Q);
  vc<T3<int>> q(Q);
  vc<int> f;
  FOR(i, Q) {
    INT(op);
    if (op == 1) {
      INT(t, x, y);
      f.ep(x);
      q[i] = {t, x, y};
    } else {
      INT(k);
      q[i] = {-k, 0, 0};
    }
  }
  unique(f);
  
  int sz = len(f), sb = 0;
  DS seg(sz);
  for (Z &[t, x, y] : q) {
    if (t >= 0) {
      x = lb(f, x);
      if (t == 1) sb += y;
      seg.multiply(x + t, t == 0 ? A{y, 0} : A{0, y});
    } else {
      Z [ty, x, y] = q[-t - 1];
      if (ty == 1) sb -= y;
      seg.multiply(x + ty, ty == 0 ? A{-y, 0} : A{0, -y});
    }

    int ta = seg.max_right([&](A x) { return x[0] <= sb - x[1]; }, 0);
    A X = seg.prod(0, ta);
    int ga = min(X[0], sb - X[1]);
    if (ta == sz) {
      if (ga == 0) print("Peace");
      else print(f[ta - 1], ga << 1);
      continue;
    }

    X = seg.prod(0, ta + 1);
    int gb = min(X[0], sb - X[1]);
    int tb = seg.max_right([&](A x) {
      x[0] += X[0], x[1] += X[1];
      return min(x[0], sb - x[1]) == gb; 
    }, ta + 1);
    if (gb >= ga) ga = gb, ta = tb;

    if (ga == 0) print("Peace");
    else print(f[ta - 1], ga << 1);
  }
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"