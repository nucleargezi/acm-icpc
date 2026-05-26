#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/flow/BM_dense.hpp"
#include "YRS/flow/submodular.hpp"
 
void Yorisou() {
  INT(N);
  vc<bs> g(N, bs(N));
  FOR(i, N) {
    INT(sz);
    FOR(sz) {
      INT(x);
      --x;
      g[i].set(x);
    }
  }
  BM_dense bm(g, N, N);

  VEC(int, a, N);
  submodular<ll, 1> f(N);
  FOR(i, N) f.add(i, 0, a[i]);
  FOR(i, N) FOR(k, N) if (g[i][k]) {
    if (bm.mat[i] == k) continue;
    f.add(i, bm.maa[k], 0, 0, inf<int>, 0);
  }
  print(f.flow());
}

int main() {
  Yorisou();
  return 0;
}