#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/debug.hpp"

#define tests
void Yorisou() {
  INT(N);
  VEC(int, a, N);
  print(QMAX(a) - QMIN(a));
}
#include "YRS/Z_H/main.hpp"