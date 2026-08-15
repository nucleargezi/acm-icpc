#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ttr/dpt/max_indset.hpp"
#include "YRS/ttr/ddp.hpp"

using DP = dp_max_indset<ll>;
void Yorisou() {
  INT(N, Q);
  VEC(int, a, N);
  vc<vc<int>> g(N);
  FOR(N - 1) {
    INT(a, b);
    --a, --b;
    g[a].ep(b), g[b].ep(a);
  }
  FOR(i, N) g[i].shrink_to_fit();
  hld v(g);
  ddp<int, DP> dp(v, [&](int i) { return DP::sing(a[i]); });
  ll ls = 0;
  FOR(Q) {
    INT(i, x);
    i ^=ls;
    --i;
    dp.set(i, DP::sing(x));
    Z s = dp.prod();
    print(ls = max(s[0][0], s[0][1]));
  }
}

int main() {
  Yorisou();
  return 0;
}