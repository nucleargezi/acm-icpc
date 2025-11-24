#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
struct dsu {
  vector<int> fa;
  dsu(int N = 0) : fa(N, -1) {}
  int f(int x) {
    while (fa[x] >= 0) {
      int p = fa[fa[x]];
      if (p < 0) return fa[x];
      x = fa[x] = p;
    }
    return x;
  }
  bool mer(int x, int y) {
    x = f(x), y = f(y);
    if (x == y) return 0;
    if (fa[x] > fa[y]) swap(x, y);
    fa[x] += fa[y];
    fa[y] = x;
    return 1;
  }
  int sz(int x) { return -fa[f(x)]; }
};
void Yorisou() {
  INT(N, M);
  VEC(string, s, N);
  dsu g(N * M);
  Z id = [&](int x, int y) -> int { return x * M + y; };
  FOR(i, N) FOR(k, M) {
    FOR(x, N) if (s[i][k] == s[x][k]) g.mer(id(i, k), id(x, k));
    FOR(y, M) if (s[i][k] == s[i][y]) g.mer(id(i, k), id(i, y));
  }
  string r;
  FOR(i, N) FOR(k, M) if (g.sz(id(i, k)) == 1) r += s[i][k];
  print(r);
}
#include "YRS/Z_H/main.hpp"