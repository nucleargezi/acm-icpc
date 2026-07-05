#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/gg/find_min_cost_C.hpp"

void Yorisou() {
  INT(op);
  INT(N, M);
  vc<vc<edge_id_w<int>>> g(N);
  FOR(i, M) {
    INT(a, b, c);
    --a, --b;
    g[a].ep(b, i, c);
    if (op == 0) g[b].ep(a, i, c);
  }

  ll rs = op == 0 ? get<0>(find_min_cost_C_undir<ll>(g))
                  : get<0>(find_min_cost_C_dir<ll>(g));
  print(rs == inf<ll> ? -1 : rs);
}

int main() {
  Yorisou();
  return 0;
}