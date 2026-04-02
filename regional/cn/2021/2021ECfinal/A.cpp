#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 1
#define fl 0
#define DB 10
void Yorisou() {
  INT(N);
  vc<vc<int>> v(N);
  FOR(N - 1) {
    INT(x, y);
    --x, --y;
    v[x].ep(y), v[y].ep(x);
  }
  vc<int> dis(N), sz(N);
  Z f = [&](Z &f, int n, int fa) -> void {
    sz[n] = 1;
    for (int x : v[n]) if (x != fa) {
      dis[x] = dis[n] + 1;
      f(f, x, n);
      sz[n] += sz[x];
    } 
  };
  f(f, 0, -1);
  FOR(i, N) print(dis[i] + 1, N - sz[i] + 1);
}
#include "YRS/aa/main.hpp"