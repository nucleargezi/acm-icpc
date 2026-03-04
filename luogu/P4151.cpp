#define YRSD
// #include "YRS/aa/fast.hpp"
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
// #include "YRS/ds/basic/retsu.hpp"
// #include "YRS/mod/mint_t.hpp"
// #include "YRS/mod/binom.hpp"
#include "YRS/g/Basic.hpp"
#include "YRS/line/01/sp.hpp"

void Yorisou() {
  INT(N, M);
  graph<ll> g(N);
  g.sc<1>(M);
  vc<ll> d(N);
  sp<ll> X;
  vc<u8> vis(N);
  Z f = [&](Z &f, int n, int fa) ->void {
    vis[n] = 1;
    for (Z &&e : g[n]) if (e.to != fa) {
      if (vis[e.to]) X.add(e.w ^ d[n] ^ d[e.to]);
      else d[e.to] = d[n] ^ e.w, f(f, e.to, n);
    }
  };
  f(f, 0, -1);
  print(X.max(d[N - 1]));
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"