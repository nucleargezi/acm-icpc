#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/math/nt/k_pre_sum.hpp"

// #define tests
using mint = M17;
void Yorisou() {
  INT(n);
  vector<mint> a(n);
  a[0] = 1;
  UL(SUM<mint>(k_pre_sum(a,  n)) * 2 - n);
}
#include "YRS/Z_H/main.hpp"