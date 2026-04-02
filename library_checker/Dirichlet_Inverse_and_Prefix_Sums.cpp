#define YRSD
// #include "YRS/aa/fast.hpp"
#include "YRS/all.hpp"
#include "YRS/IO/fast_io.hpp"
#include "YRS/mod/mint_t.hpp"
#include "YRS/pr/diri.hpp"

using mint = M99;
void Yorisou() {
  LL(N);
  diri X(N);
  int n = X.n;
  vc<mint> f(n);
  FOR(i, 1, n) IN(f[i]);
  f = X.div(X.unit<mint>(), f);
  f.erase(bg(f));
  print(f);
}
constexpr int tests = 1, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"