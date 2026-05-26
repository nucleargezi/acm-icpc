#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/basic/retsu.hpp"
#include "YRS/ds/basic/queue.hpp"
#include "YRS/ds/un/dsu.hpp"
#include "YRS/jen/rasen.hpp"

constexpr int B = 777;
const retsu rg = rasen(B, B).rol90().rol90().rol90().rev();
int gi(int x, int y) { return rg[B / 2 + x][B / 2 + y]; }
void Yorisou() {
  INT(N, M);
  retsu<int> a(N, M), b(N, M);
  IN(a, b);
  vc<int> u{0};
  FOR(i, N) FOR(k, M) u.ep(a[i][k]);
  FOR(i, N) FOR(k, M) if (b[i][k] != -1) u.ep(b[i][k]);
  unique(u);
  int sz = si(u);
  FOR(i, N) FOR(k, M) a[i][k] = lb(u, a[i][k]);
  FOR(i, N) FOR(k, M) if (b[i][k] != -1) b[i][k] = lb(u, b[i][k]);
  INT(x, y);
  --x, --y;

  dsu g(sz);
  vc<int> c(sz);
  FOR(i, N) FOR(k, M) ++c[a[i][k]];
  vc<int> cl(sz), to(sz);
  iota(all(cl), 0);
  iota(all(to), 0);
  vc<vc<PII>> v(sz);
  FOR(i, N) FOR(k, M) if (b[i][k] != -1 and not(x == i and y == k)) v[a[i][k]].ep(i, k);

  queue<PII> q;
  q.eb(x, y);
  ll rs = 0;
  while (si(q)) {
    Z [x, y] = pop(q);
    int t = b[x][y], col = cl[g[a[x][y]]];
    if (col == 0 or t == col) continue;
    int k = to[col];
    vc<PII> st = v[k];
    vc<int> idx;
    for (var [a, b] : st) idx.ep(gi(a - x, b - y));
    st = rearrange(st, argsort(idx));
    for (var [a, b] : st) q.eb(a, b);
    v[k].clear();
    rs += c[k];
    if (to[t] == -1) {
      to[col] = -1;
      to[t] = k;
      cl[k] = t;
      continue;
    }
    int j = to[t];
    g.merge(k, j);
    int fa = g[k], i = fa ^ k ^ j;
    c[fa] += c[i];
    c[i] = 0;
    cl[i] = -1;
    v[fa].insert(ed(v[fa]), all(v[i]));
    v[i].clear();
    cl[fa] = t;
    to[col] = -1;
    to[t] = fa;
  }
  print(rs);
}

int main() {
  Yorisou();
  return 0;
}