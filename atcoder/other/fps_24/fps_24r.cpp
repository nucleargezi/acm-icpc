#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/po/c/ntt.hpp"

#define tests 0
#define fl 0
#define DB 10
using mint = M99;
using fps = vc<mint>;
void Yorisou() {
  LL(N, T, x);
  --x;  
  int sz = 1 << (N + 1);
  fps f(sz);
  f[1] = f[sz - 1] = mint(2).inv();
  ntt(f, 0);
  FOR(i, sz) f[i] = f[i].pow(T);
  ntt(f, 1);
  mint ans = f[x];
  if (x != 0 and x != (1 << N)) ans += f[sz - x];
  print(ans);
}
#include "YRS/aa/main.hpp"