#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/flow/max_flow.hpp"

void Yorisou() {
  INT(W);
  INT(N);
  VEC(int, a, N);
  INT(M);
  VEC(int, b, M);
  int s = N + M, t = s + 1;
  max_flow<int> g(t + 1, s, t);
  FOR(i, N) g.add(s, i, a[i]);
  FOR(i, M) g.add(i + N, t, b[i]);
  
  vc<u8> vis(N);
  FOR(i, M) {
    fill(all(vis), 1);
    INT(sz);
    FOR(sz) {
      INT(x);
      vis[x - 1] = 0;
    }
    FOR(k, N) if (vis[k]) g.add(k, i + N, a[k]);
  }
  print(g.flow() >= W ? "SHIROBAKO" : "BANSAKUTSUKITA");
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"