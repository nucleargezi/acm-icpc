#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ttr/near_kinbo.hpp"

void Yorisou() {
  INT(N, Q);
  vc<vc<int>> g(N);
  FOR(N - 1) {
    INT(a, b);
    --a, --b;
    g[a].ep(b), g[b].ep(a);
  }
  near_kinbo v(g);
  vc<int> c(si(v));
  FOR(i, N) v.vs(i, [&](int x) { ++c[x]; });
  c = pre_sum(c);

  FOR(Q) {
    INT(x, k);
    --x;
    int s = 0;
    v.range(x, k, k + 1, [&](int l, int r) {
      s += c[r] - c[l];
    });
    print(s);
  }
}

int main() {
  INT(T);
  FOR(T) Yorisou();
}