#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
#include "YRS/ds/basic/queue.hpp"

void Yorisou() {
  INT(N, M);
  vc<vc<int>> g(N);
  vc<int> in(N);
  FOR(M) {
    INT(x, y);
    --x, --y;
    g[x].ep(y);
    g[y].ep(x);
    ++in[x], ++in[y];
  }
  FOR(i, N) in[i] >>= 1;
  queue<int> q;
  q.eb(0);
  vc<u8> vis(N);
  vc<int> ans;
  while (not q.empty()) {
    int n = pop(q);
    vis[n] = 1;
    ans.ep(n);
    if (n != 0 and n != 1 and in[n] < 0) return print("NIE");
    for (int x : g[n]) if (not vis[x]) {
      if (not --in[x] and x != 1) q.eb(x);
    }
  }
  FOR(i, 2, N) if (not in[i] and not vis[i]) ans.ep(i);
  ans.ep(1);
  if (len(ans) != N) return print("NIE");
  print("TAK");
  ans = inverse(ans);
  FOR(i, N) ++ans[i];
  print(ans);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"