#include "YRS/Z_H/MeioN.hpp"
#include "YRS/MeIoN_all.hpp"
#include "YRS/math/mod/modint.hpp"
#include "YRS/math/PR/convolution_gcd.hpp"

// #define tests
using mint = M99;
void Yorisou() {
  INT(n);
  VEC(mint, a, n);
  VEC(mint, b, n);
  a.insert(a.begin(), 0);
  b.insert(b.begin(), 0);
  vector ans = convolution_gcd(a, b);
  ans.erase(ans.begin());
  UL(ans);
}
#include "YRS/Z_H/main.hpp"