#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/gg/steiner.hpp"

void Yorisou() {
  INT(N, M, K);
  vc<vc<edge_id_w<int>>> g(N);
  FOR(i, M) {
    INT(a, b, c);
    --a, --b;
    g[a].ep(b, i, c);
    g[b].ep(a, i, c);
  }
  VEC(int, s, K);
  for (int &x : s) --x;
  print(get<0>(steiner(g, s)));
}

int main() {
  Yorisou();
  return 0;
}