#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/flow/BM.hpp"

void Yorisou() {
  INT(N, M);
  STR(a, b);
  int s = 0;
  FOR(i, N) if (a[i] == b[i]) s |= 1 << i;
  vc<u8> vis(1 << N);
  FOR(i, M) {
    int t = 0;
    STR(str);
    FOR(k, N) if (str[k] == '=') t |= 1 << k;
    t ^= s;
    vis[t] = 1;
  }
  graph g(1 << N);
  FOR(s, 1 << N) if (not vis[s]) {
    FOR(k, N) if (not(s >> k & 1) and not vis[1 << k | s]) {
      g.add(s, 1 << k | s);
    }
  }
  g.build();
  int mx = len(B_matching(g).matching());
  g = graph(1 << N);
  FOR(s, 1, 1 << N) if (not vis[s]) {
    FOR(k, N) if (not(s >> k & 1) and not vis[1 << k | s]) {
      g.add(s, 1 << k | s);
    }
  }
  g.build();
  int ne = len(B_matching(g).matching());
  Alice(mx != ne);
}
constexpr int tests = 1, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"