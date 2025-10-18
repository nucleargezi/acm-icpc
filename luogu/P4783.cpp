#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/math/line/mat_vec.hpp"
#include "YRS/math/mod/modint.hpp"

// #define tests
using mint = M17;
void Yorisou() {
  INT(n);
  VVEC(mint, in, n, n);
  MAT<mint> a(in);
  meion [det, res] = a.inv();
  if (det == 0) iroha UL("No Solution");
  FOR(i, n) UL(res[i]);
}
#include "YRS/Z_H/main.hpp"