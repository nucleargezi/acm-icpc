#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/g/dijkstra.hpp"

void Yorisou() {
  INT(N, M, s, t);
  graph<int, 1> g(N);
  g.sc<1, 0>(M);
  Z [d, f] = dijkstra<ll>(g, s);
  if (d[t] == inf<ll>) return print(-1);
  int x = t;
  vc<int> pa;
  while (x != -1) pa.ep(x), x = f[x];
  reverse(pa);
  int sz = si(pa);
  print(d[t], sz - 1);
  FOR(i, sz - 1) print(pa[i], pa[i + 1]);
}

int main() {
  Yorisou();
  return 0;
}