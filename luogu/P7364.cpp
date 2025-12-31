#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/po/cg/label_bipartite.hpp"

#define tests 0
#define fl 0
#define DB 10
using mint = M99;
void Yorisou() {
  vc<mint> f = count_label_bipartite<mint>(1'000'00, 0);
  FOR(i, 1, 1'000'01) print(f[i]);
}
#include "YRS/aa/main.hpp"