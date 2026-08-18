#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/gg/mdst.hpp"

void Yorisou() {
  INT(N, M);
  vc<vc<edge_id_w<int>>> g(N);
  FOR(i, M) {
    INT(a, b, c);
    g[a].ep(b, i, c);
    g[b].ep(a, i, c);
  }
  Z [S, e] = mdst(g);
  print(S);
  print(e);
}

int main() {
  Yorisou();
  return 0;
}