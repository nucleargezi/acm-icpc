#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
// #include "YRS/ds/basic/retsu.hpp"
// #include "YRS/mod/mint.hpp"
#include "YRS/po/all.hpp"
#include "YRS/po/coef_of_rational_fps.hpp"

#define tests 0
#define fl 0
#define DB 10
using mint = mint_t<123'456'789'1>;
using fps = vc<mint>;
void Yorisou() {
  LL(N, V);
  VEC(int, a, N);
  fps f{1};
  for (int x : a) {
    fps g(x + 1);
    g[0] = 1;
    g[x] -= 1;
    f = f * g;
  }
  print(coef_of_rational_fps(fps{1}, f, V));
}
#include "YRS/aa/main.hpp"