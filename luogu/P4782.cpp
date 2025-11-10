#include "YRS/all.hpp"
#include "YRS/debug.hpp"

struct Sat {
  int N;
  vector<vector<int>> v;
  vector<int> ans, dfn, low, id, s;
  vector<char> vis;
  int t = 0, c = 0;

  Sat(int N) : N(N), v(N << 1), ans(N), dfn(N << 1), low(N << 1), id(N << 1), vis(N << 1) {};

  void add(int x, int y) {
    v[x].ep(y);
    v[y ^ 1].ep(x ^ 1);
  }
  void ban(int x, int y, int xx, int yy) {
    xx ^= 1, add(x << 1 | xx, y << 1 | yy);
  }
  bool solve() {
    FOR(i, N << 1) if (not dfn[i]) f(i);
    FOR(i, N) {
      if (id[i << 1] == id[i << 1 | 1]) return false;
      ans[i] = id[i << 1] < id[i << 1 | 1];
    }
    return true;
  }
  
  void f(int n) {
    dfn[n] = low[n] = ++t;
    vis[n] = 1;
    s.ep(n);
    for (int x : v[n]) {
      if (not dfn[x]) f(x), chmin(low[n], low[x]);
      else if (vis[x]) chmin(low[n], dfn[x]);
    }
    if (dfn[n] == low[n]) {
      while (1) {
        int x = pop(s);
        id[x] = c;
        vis[x] = 0;
        if (x == n) break;
      }
      ++c;
    }
  }
};
void Yorisou() {
  INT(N, Q);
  Sat g(N);
  FOR(Q) {
    INT(x, xx, y, yy);
    --x, --y;
    g.ban(x, y, not xx, not yy);
  }
  if (g.solve()) {
    POSSIBLE();
    print(g.ans);
  } else IMPOSSIBLE();
}
#include "YRS/Z_H/main.hpp"