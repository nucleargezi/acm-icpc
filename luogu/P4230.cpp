#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/ds/lct/lct_simple.hpp"
#include "YRS/IO/fast_io.hpp"

// #define tests
using DS = LCT_simple;
void Yorisou() {
  INT(M);
  VEC(PII, e, M);
  int N = 0;
  for (Z &[x, y] : e) {
    chmax(N, x), chmax(N, y);
    --x, --y;
  }
  DS lct(N);
  int l = 0;
  vector<ll> a(M + 1), b(M + 1);
  Z add = [&](int l, int r) -> void {
    a[l] += M - r + 1;
    a[r] -= M - r + 1;
    b[r] += 1;
  };
  FOR(r, M) {
    Z [x, y] = e[r];
    while (lct.get_rt(x) == lct.get_rt(y)) {
      add(l, r + 1);
      Z [x, y] = e[l++];
      lct.cut(x, y);
    }
    lct.link(x, y);
  }
  a = pre_sum<0>(a);
  b = pre_sum<0>(b);
  FOR(i, M) a[i] += b[i] * (M - i);
  a.resize(M);
  print(a);
}
#include "YRS/Z_H/main.hpp"