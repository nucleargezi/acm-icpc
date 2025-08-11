#include "YRS/Z_H/MeioN.hpp"
#include "YRS/MeIoN_all.hpp"
#include "YRS/ds/lis.hpp"

// #define tests
void Yorisou() {
  INT(n);
  VEC(int, a, n);
  vector ans = lis(a);
  UL(len(ans));
  UL(ans);
}
#include "YRS/Z_H/main.hpp"