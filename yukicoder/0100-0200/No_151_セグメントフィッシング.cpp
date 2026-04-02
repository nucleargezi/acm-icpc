#define YRSD
// #include "YRS/aa/fast.hpp"
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
// #include "YRS/ds/basic/retsu.hpp"
// #include "YRS/mod/mint.hpp"
// #include "YRS/aa/def.hpp"
#include "YRS/ds/bit/bit.hpp"
#include "YRS/al/m/add.hpp"

using MX = monoid_add<ll>;
void Yorisou() {
  INT(N, Q);
  int nn = N << 1;
  bit_t<MX> a(nn);
  Z f = [&](int i) { return (i %= nn) < 0 ? i + nn : i; };
  FOR(i, Q) {
    CH(op);
    INT(y, z);
    if (op == 'C') {
      ll s = 0;
      int l = y, r = z;
      l = f(l - i), r = f(r - i);
      if (l > r) s += a.prod(l, nn) + a.prod(0, r);
      else s += a.prod(l, r);
      l = nn - z, r = nn - y;
      l = f(l - i), r = f(r - i);
      if (l > r) s += a.prod(l, nn) + a.prod(0, r);
      else s += a.prod(l, r);
      print(s);
    } else if (op == 'L') {
      y = f(nn - y - 1 - i);
      a.multiply(y, z);
    } else {
      y = f(y - i);
      a.multiply(y, z);
    }
  }
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"