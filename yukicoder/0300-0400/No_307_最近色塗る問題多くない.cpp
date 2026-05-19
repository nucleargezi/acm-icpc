#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/basic/retsu.hpp"

struct dsu {
  int c;
  vc<int> fa;
  vc<vc<int>> v;
  dsu(int N = 0) : c(N), fa(N, -1), v(N) {
    FOR(i, N) v[i].ep(i);
  }

  int f(int x) {
    while (fa[x] >= 0) {
      int p = fa[fa[x]];
      if (p < 0) return fa[x];
      x = fa[x] = p;
    }
    return x;
  }

  int operator[](int x) { return f(x); }

  bool merge(int x, int y) {
    x = f(x), y = f(y);
    if (x == y) return 0;
    if (fa[x] > fa[y]) swap(x, y);
    fa[x] += fa[y];
    v[x].insert(ed(v[x]), all(v[y]));
    fa[y] = x;
    --c;
    return 1;
  }
};
void Yorisou() {
  INT(N, M);
  retsu<int> id(N, M);
  vc<char> c(N * M);
  FOR(i, N) FOR(k, M) {
    INT(x);
    c[i * M + k] = x;
  }
  dsu g(N * M);
  iota(all(id.a), 0);
  FOR(i, N) FOR(k, M) {
    if (i and c[g[id[i][k]]] == c[g[id[i - 1][k]]]) g.merge(id[i][k], id[i - 1][k]);
    if (k and c[g[id[i][k]]] == c[g[id[i][k - 1]]]) g.merge(id[i][k], id[i][k - 1]);
  }
  vc<PII> se;
  FOR(i, N) FOR(k, M) {
    if (i and c[g[id[i][k]]] != c[g[id[i - 1][k]]]) se.ep(id[i][k], id[i - 1][k]);
    if (k and c[g[id[i][k]]] != c[g[id[i][k - 1]]]) se.ep(id[i][k], id[i][k - 1]);
  }
  INT(Q);
  FOR(Q) {
    INT(x, y, a);
    --x, --y;
    int ii = g[id[x][y]];
    c[g[id[x][y]]] = a;
    if (g.c == 1) continue;
    if (si(g.v[ii]) < 100) {
      static vc<int> b;
      b.clear();
      for (int x : g.v[ii]) b.ep(x);
      for (int t : b) {
        int x = t / M, y = t % M;
        static constexpr int dx[]{1, -1, 0, 0}, dy[]{0, 0, 1, -1};
        FOR(d, 4) {
          int xx = x + dx[d], yy = y + dy[d];
          if (min(xx, yy) >= 0 and xx < N and yy < M) {
            if (c[g[id[x][y]]] == c[g[id[xx][yy]]]) g.merge(id[x][y], id[xx][yy]);
          }
        }
      }
    } else {
      FOR_R(j, si(se)) {
        var [i, k] = se[j];
        if (c[g[i]] == c[g[k]]) {
          g.merge(i, k);
          se.erase(bg(se) + j);
        }
      }
    }
  }
  FOR(i, N) FOR(k, M) {
    put((int)c[g[id[i][k]]], " \n"[k + 1 == M]);
  }
}

int main() {
  Yorisou();
  return 0;
}