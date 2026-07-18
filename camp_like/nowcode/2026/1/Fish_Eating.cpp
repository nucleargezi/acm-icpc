#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/basic/retsu.hpp"

struct dsu {
  int c;
  vc<int> fa, dat, mx;
  dsu(int N = 0) : c(N), fa(N, -1), dat(N), mx(N) {}

  int f(int x) {
    if (fa[x] < 0) return x;
    int y = fa[x], p = f(y);
    chmax(mx[x], mx[y]);
    return fa[x] = p;
  }

  int operator[](int x) { return f(x); }

  bool set(int x, int y) {
    x = f(x), y = f(y);
    if (x == y) return 0;
    chmax(mx[y], dat[x] + fa[y]);
    fa[x] += fa[y];
    fa[y] = x;
    --c;
    return 1;
  }
};

void Yorisou() {
  INT(N, M, Q);
  dsu g(N * M);
  int ls = 0;
  Z id = [&](int a, int b) { return a * M + b; };
  retsu<char> vis(N, M);
  FOR(Q) {
    INT(op, x, y);
    x ^= ls, y ^= ls;
    --x, --y;
    int i = id(x, y);
    static constexpr int dx[]{1, -1, 0, 0}, dy[]{0, 0, 1, -1};
    if (op == 1) {
      INT(w);
      vis[x][y] = 1;
      g.dat[i] = w;
      FOR(d, 4) {
        int xx = x + dx[d], yy = y + dy[d];
        if (min(xx, yy) >= 0 and xx < N and yy < M) {
          if (vis[xx][yy]) {
            g.set(i, id(xx, yy));
          }
        }
      }
      i = g[i];
      print(ls = -g.fa[i] - 1);
    } else {
      g[i];
      print(ls = max(0, g.mx[i] - g.dat[i] + 1));
    }
  }
}

int main() {
  Yorisou();
  return 0;
}