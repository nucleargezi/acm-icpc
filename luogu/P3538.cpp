#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/string/hash.hpp"
#include "YRS/math/PR/lpf_table.hpp"
#include "YRS/math/PR/divisors.hpp"

// #define tests
void Yorisou() {
  INT(N);
  STR(s);
  hash seg(s);
  Z lpf = lpf_table(N);
  INT(Q);
  FOR(Q) {
    INT(l, r);
    --l;
    int sz = r - l;
    Z fac = factor(sz);
    for (Z &[e, c] : fac) {
      while (c) {
        int t = sz / e;
        if (seg.get(l, r - t) == seg.get(l + t, r)) --c, sz /= e;
        else break;
      }
    }
    print(sz);
  } 
}
#include "YRS/Z_H/main.hpp"