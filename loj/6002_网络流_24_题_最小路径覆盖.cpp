#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/gg/dag_path_cover.hpp"

void Yorisou() {
  INT(N, M);
  vc<vc<int>> g(N);
  vc<int> in(N);
  FOR(M) {
    INT(a, b);
    --a, --b;
    g[a].ep(b);
    ++in[b];
  }
  vc<int> V, id(N);
  FOR(i, N) if (in[i] == 0) V.ep(i);
  FOR(i, si(V)) {
    int n = V[i];
    for (int x : g[n]) if (--in[x] == 0) V.ep(x);
  }
  FOR(i, N) id[V[i]] = i;
  g = rearrange(g, V);
  FOR(n, N) for (int &x : g[n]) x = id[x];

  Z s = dag_path_cover_paths(g);
  for (Z &s : s) {
    for (int &x : s) x = V[x] + 1;
    print(s);
  }
  print(si(s));
}

int main() {
  Yorisou();
  return 0;
}