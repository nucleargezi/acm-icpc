#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/math/mod/modint.hpp"
#include "YRS/math/line/det.hpp"

// #define tests
void Yorisou() {
  LL(N, mod);
  VVEC(int, a, N, N);
  int ans = det(a, mod);
  UL(ans);
}
#include "YRS/Z_H/main.hpp"