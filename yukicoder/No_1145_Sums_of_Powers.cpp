#include "YRS/all.hpp"
#include "YRS/po/sum_of_pow.hpp"

using mint = M99;
void Yorisou() {
  INT(N, K);
  VEC(mint, a, N);
  vc<mint> r = sum_of_pow(a, K);
  r.erase(r.begin());
  print(r);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"