#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ttr/top_cluster_set.hpp"

void Yorisou() {
  INT(N, Q);
  VEC(int, a, N);
  vc<int> f(a);
  unique(f);
  for (int &x : a) x = lb(f, x);
  vc<vc<int>> g(N);
  FOR(N - 1) {
    INT(a, b);
    --a, --b;
    g[a].ep(b);
    g[b].ep(a);
  }
  top_cluster_set v(g, a);
  int ls = 0;
  FOR(Q) {
    INT(a, b);
    a ^= ls;
    --a, --b;
    print(ls = v.prod(a, b));
  }
}

int main() {
  Yorisou();
  return 0;
}