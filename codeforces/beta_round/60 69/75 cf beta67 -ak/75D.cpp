#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/ds/monoid/max_sub_array_sum.hpp"

// #define tests
using mono = monoid_max_subarray_sum<ll>;
using X = mono::X;
void Yorisou() {
  INT(N, M);
  vector<X> dat;
  FOR(N) {
    INT(sz);
    VEC(int, a, sz);
    X seg = mono::unit();
    for (int x : a) seg = mono::op(seg, mono::from_element(x));
    dat.ep(seg);
  }
  X ans = mono::unit();
  FOR(M) {
    INT(x);
    --x;
    ans = mono::op(ans, dat[x]);
  }
  print(ans.mx);
}
#include "YRS/Z_H/main.hpp"