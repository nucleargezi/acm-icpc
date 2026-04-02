#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/ge/all.hpp"

// #define tests
using RE = double;
using P = point<RE>;
void Yorisou() {
  LL(n);
  P a, b, c, d;
  FOR(i, n) {
    IN(a, b, c, d);
    line X(a, b), Y(c, d);
    UL(X.is_orth(Y) ? 1 : X.is_para(Y) ? 2 : 0);
  }
}
#include "YRS/Z_H/main.hpp"