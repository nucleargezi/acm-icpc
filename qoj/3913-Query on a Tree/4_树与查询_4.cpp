#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/IO/yn.hpp"
#include "YRS/ttr/ddp.hpp"
#include "YRS/ttr/dpt/wb_dist.hpp"

using DP = dp_wb_dist<ll>;
void Yorisou() {
  INT(N);
  vc<vc<int>> g(N);
  VEC(T3<int>, es, N - 1);
  for (Z &[a, b, c] : es) {
    --a, --b;
    g[a].ep(b), g[b].ep(a);
  }
  hld v(g, 0);
  vc<int> w(N);
  for (var [a, b, c] : es) w[v.d[a] > v.d[b] ? a : b] = c;
  Z sing = [&](int i) { return DP::set(w[i]); };
  ddp<int, DP> dp(v, sing);

  vc<char> vis(N);
  INT(Q);
  FOR(Q) {
    INT(op);
    if (op == 1) {
      INT(x);
      --x;
      if (vis[x]) dp.set(x, DP::set(w[x]));
      else dp.set(x, DP::reset(w[x]));
      vis[x] ^= 1;
    } else {
      ll rs = dp.prod().ans;
      print(rs < 0 ? -1 : rs);
    }
  }
}

int main() {
  Yorisou();
  return 0;
}