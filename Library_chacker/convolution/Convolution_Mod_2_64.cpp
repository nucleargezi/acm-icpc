#include "YRS/Z_H/MeioN.hpp"
#include "YRS/MeIoN_all.hpp"
#include "YRS/math/poly/convolution_u64.hpp"

// #define tests
void Yorisou() {
  INT(n, m);
  VEC(ull, a, n);
  VEC(ull, b, m);
  UL(convolution_u64(a, b));
}
#include "YRS/Z_H/main.hpp"