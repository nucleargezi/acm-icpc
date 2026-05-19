#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/g/unicycle_forest.hpp"

void Yorisou() {
  INT(N);
  VEC(int, f, N);
  VEC(int, w, N);
  vc<PII> e;
  FOR(i, N) e.ep(f[i] - 1, i);
  Z [C, vs, es, fa, fe, rs, g] = unicycle_forest(N, e);
  ll s = 0;
  FOR(i, C) {
    int mx = inf<int>;
    for (int x : vs[i]) chmin(mx, w[x]);
    s += mx;
  }
  print(s);
}

int main() {
  Yorisou();
  return 0;
}