#define YRSD
// #include "YRS/aa/fast.hpp"
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
// #include "YRS/ds/basic/retsu.hpp"
// #include "YRS/mod/mint.hpp"
// #include "YRS/aa/def.hpp"
#include "YRS/ds/un/dsu.hpp"
#include "YRS/ge/exp/mst.hpp"

using P = point<ll>;
void Yorisou() {
  INT(N);
  VEC(P, a, N);
  dsu g(N);
  ll s = 0;
  vc<PII> es;
  for (Z [w, x, y] : manhattan_mst(a)) {
    if (g.merge(x, y)) s += w, es.ep(x + 1, y + 1);
  }
  print(s);
  for (Z x : es) print(x);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"