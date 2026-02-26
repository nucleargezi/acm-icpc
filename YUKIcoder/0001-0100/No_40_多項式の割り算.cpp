#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/po/all.hpp"
#include "YRS/po/poly_divmod.hpp"

#define tests 0
#define fl 0
#define DB 10
using mint = M99;
using fps = vc<mint>;
D_poly()
void Yorisou() {
  INT(N);
  VEC(mint, f, N + 1);
  Z [_, g] = poly_divmod(f, "x^3-x"_p);
  if (g.empty()) g = {0};
  vc<int> res;
  for (mint &x : g) res.ep(x.val > 1000000 ? -(-x).val : x.val);
  print(len(res) - 1);
  print(res);
}
#include "YRS/aa/main.hpp"