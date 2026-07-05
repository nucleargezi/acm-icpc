#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ttr/ddp.hpp"
#include "YRS/ttr/dpt/pair_lca_dep_sum.hpp"

using DP = pair_lca_dep_sum;
void Yorisou() {
  INT(N, Q);
  VEC(int, c, N);
  vc<vc<int>> g(N);
  FOR(i, 1, N) {
    INT(f);
    --f;
    g[f].ep(i);
    g[i].ep(f);
  }
  hld v(g, 0);
  Z sing = [&](int i) {
    return DP::sing(c[i], v.d[i], v.fa[i] == -1 ? 0 : v.d[v.fa[i]]);
  };
  ddp<int, DP> dp(v, sing);
  print(dp.prod().rs);
  FOR(Q) {
    INT(x);
    --x;
    c[x] ^= 1;
    dp.set(x, sing(x));
    print(dp.prod().rs);
  }
}

int main() {
  Yorisou();
  return 0;
}