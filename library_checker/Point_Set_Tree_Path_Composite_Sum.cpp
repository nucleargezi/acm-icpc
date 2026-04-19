#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/mod/mint_t.hpp"
#include "YRS/tr/ddp_re.hpp"

using mint = M99;
using DP = DP_mode<mint>;
using dat = DP::X;
void Yorisou() {
  INT(N, Q);
  graph g(N);
  VEC(mint, a, N);
  vc<pair<mint, mint>> es(N - 1);
  FOR(i, N - 1) {
    INT(x, y, a, b);
    es[i] = {a, b};
    g.add(x, y);
  }
  g.build();
  hld v(g);
  
  Z sing = [&](int i) -> pair<dat, dat> {
    if (i == 0) {
      dat up = {0, -1, 0, 1, 0, 1, a[i]};
      dat down = {1, 0, -1, 1, 0, 1, a[i]};
      return {up, down};
    }
    int e = v.ve(i), p = v.fa[i];
    dat up = {0, p, i, es[e].fi, es[e].se, 1, es[e].fi * a[i] + es[e].se};
    dat down = {1, i, p, es[e].fi, es[e].se, 1, a[i]};
    return {up, down};
  };

  dynamic_tree_dp_re<int, DP> dp(v, sing);
  FOR(Q) {
    INT(op);
    if (op == 0) {
      INT(i, x);
      a[i] = x;
      dp.set(i, sing(i));
    }
    if (op == 1) {
      INT(i, b, c);
      es[i] = {b, c};
      i = v.ev(i);
      dp.set(i, sing(i));
    }
    INT(i);
    print(dp.prod(i).ans);
  }
}

int main() {
  Yorisou();
  return 0;
}