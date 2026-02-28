#define YRSD
// #include "YRS/aa/fast.hpp"
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
// #include "YRS/ds/basic/retsu.hpp"
// #include "YRS/mod/mint.hpp"
// #include "YRS/aa/def.hpp"
#include "YRS/nt/bigint/big.hpp"

void Yorisou() {
  using ll = bigint;
  STR(s);
  map<int, int> mp;
  for (int x : s) ++mp[x];
  int N = len(s);
  vc<ll> fa(N + 1);
  fa[0] = 1;
  FOR(i, 1, N + 1) fa[i] = fa[i - 1] * i;
  ll ans = fa[N];
  for (Z [x, y] : mp) ans /= fa[y];
  print((ans - 1) % 573);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"