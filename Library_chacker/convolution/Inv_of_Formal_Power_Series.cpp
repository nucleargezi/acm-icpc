#include "YRS/all.hpp"
#include "YRS/po/fps_inv.hpp"

// #define tests
using mint = M99;
void Yorisou() {
  INT(n);
  VEC(mint, a, n);
  print(fps_inv(a));
}