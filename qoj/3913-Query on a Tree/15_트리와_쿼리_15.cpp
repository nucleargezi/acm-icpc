#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ttr/tree_ball_union.hpp"

void Yorisou() {
  INT(N);
  vc<vc<int>> g(N);
  FOR(N - 1) {
    INT(a, b);
    --a, --b;
    g[a].ep(b), g[b].ep(a);
  }
  tree_ball_union ds(g);

  INT(Q);
  vc<PII> q(N);
  FOR(Q) {
    INT(k);
    q.resize(k);
    IN(q);
    for (Z &[a, b] : q) --a;
    print(ds.prod(std::move(q)));
  }
}

int main() {
  Yorisou();
  return 0;
}