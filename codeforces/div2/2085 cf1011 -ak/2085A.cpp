#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"

#define tests
void Yorisou() {
  INT(N, K);
  STR(s);
  if (not K) return YES(s < reversed(s));
  YES(QMAX(s) != QMIN(s));
}
#include "YRS/Z_H/main.hpp"