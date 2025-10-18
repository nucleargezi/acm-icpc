#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/ge/exp/circle_inverse.hpp"

#define tests
using RE = long double;
void Yorisou() {
  REAL(R, r);
  INT(K);
  setp(10);
  print(circle_inverse_exp(R, r, K));
}
#include "YRS/Z_H/main.hpp"