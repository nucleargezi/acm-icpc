#include "YRS/all.hpp"
#include "YRS/mod/modint.hpp"
#include "YRS/pr/convolution_lcm.hpp"

// #define tests
using mint = M99;
void Yorisou() {
  INT(n);
  VEC(mint, a, n);
  VEC(mint, b, n);
  a.insert(a.begin(), 0);
  b.insert(b.begin(), 0);
  vector ans = convolution_lcm(a, b);
  ans.erase(ans.begin());
  print(ans);
}