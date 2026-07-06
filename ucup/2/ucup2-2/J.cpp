#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

using re = ld;
struct E {
  int to, op;
  re w;
  operator int() const { return to; }
};
constexpr int M = 101;
void Yorisou() {
  INT(N, e);
  INT(x, y, xx, yy);
  int id[M + M][M + M]{};

  int tot = 0;
  vc<PII> ps(M * M);
  FOR(i, M) FOR(k, M) ps[tot] = {i, k}, id[i][k] = tot++;

  int ss = id[x][y], tt = id[xx][yy];
  vc<vc<E>> g(M * M * 2);
  FOR(i, M) FOR(k, M) {
    int dx = abs(x - i), dy = abs(y - k);
    re d = sqrtl(dx * dx + dy * dy);
    g[ss].ep(E{id[i][k], 0, d});
    g[id[i][k]].ep(E{ss, 0, d});
    dx = abs(xx - i), dy = abs(yy - k);
    d = sqrtl(dx * dx + dy * dy);
    g[id[i][k]].ep(E{tt, 0, d});
    g[tt].ep(E{id[i][k], 0, d});
  }

  map<PII, int> ii;
  FOR(t, N) {
    INT(x, y);
    int i = id[x][y];
    ii[{x, y}] = t + 1;
    FOR(k, M) {
      g[i + M * M].ep(E{id[x][k], 1, (re)e});
      g[id[x][k]].ep(E{i + M * M, 1, 0});
    }
    FOR(k, M) {
      g[i + M * M].ep(E{id[k][y], 1, (re)e});
      g[id[k][y]].ep(E{i + M * M, 1, 0});
    }
    FOR(j, M) FOR(k, M) {
      if (not(j == x and k == y)) {
        int dx = abs(j - x), dy = abs(k - y);
        re d = sqrtl(dx * dx + dy * dy);
        g[i].ep(E{id[j][k], 0, d});
        g[id[j][k]].ep(E{i, 0, d});
      }
    }
  }
  
  min_heap<pair<re, int>> q;
  vc<re> dis(M * M * 2, M * M * 2 + 1);
  q.eb(dis[ss] = 0, ss);
  vc<int> fa(M * M * 2, -1);
  while (si(q)) {
    Z [d, n] = pop(q);
    if (d != dis[n]) continue;
    for (var e : g[n]) {
      if (chmin(dis[e], d + e.w)) {
        fa[e] = n;
        q.eb(d + e.w, e);
      }
    }
  }
  setp(10);
  print(dis[tt]);
  vc<T3<int>> pa;
  while (fa[tt] != -1) {
    int a = fa[tt];
    var [x, y] = ps[tt];
    if (a >= M * M) {
      tt = a;
      int xx = (a - M * M) / M, yy = (a - M * M) % M;
      a = fa[tt];
      pa.ep(ii[{xx, yy}], x, y);
    } else {
      pa.ep(0, x, y);
    }
    tt = a;
  }
  reverse(pa);
  print(si(pa));
  for (var [a, b, c] : pa) print(a, b, c);
}

int main() {
  Yorisou();
  return 0;
}