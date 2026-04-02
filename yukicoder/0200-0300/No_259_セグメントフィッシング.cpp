#include "YRS/all.hpp"
#include "YRS/IO/fast_io.hpp"
#include "YRS/ds/seg/range_sum_point_add.hpp"
#include "YRS/al/m/add.hpp"

using MX = monoid_add<ll>;
using DS = range_sum_point_add<MX>;
void Yorisou() {
  INT(N, Q);
  int n = N << 1;
  Z f = [&](int x) { return (x % n + n) % n; };
  DS seg(n);
  FOR(Q) {
    CH(op);
    INT(t, y, z);
    if (op == 'C') {
      ll s = 0;
      int l = f(y - t), r = f(z - t);
      if (l < r) s += seg.prod(l, r);
      else s += seg.prod(0, r) + seg.prod(l, n);
      l = f(n - z - t), r = f(n - y - t);
      if (l < r) s += seg.prod(l, r);
      else s += seg.prod(0, r) + seg.prod(l, n);
      print(s);
    } else {
      if (op == 'L') y = n - 1 - y;
      int i = f(y - t);
      seg.multiply(i, z);
    }
  }
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"