#include "YRS/all.hpp"
#include "YRS/math/line/det.hpp"
#include "YRS/math/mod/modint_d.hpp"

// #define tests
using mint = dmint;
void Yorisou() {
  LL(n, p);
  VVEC(int, a, n, n);
  FOR(i, n) FOR(k, n) a[i][k] %= p;
  UL(det(a, p));
}
#include "YRS/Z_H/main.hpp"