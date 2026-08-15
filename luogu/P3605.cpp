#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ttr/tr.hpp"
#include "YRS/ds/wave/sswave.hpp"

void Yorisou() {
  INT(N);
  VEC(int, a, N);
  vc<vc<int>> g(N);
  FOR(i, 1, N) {
    INT(f);
    --f;
    g[f].ep(i);
    g[i].ep(f);
  }
  tr v(g, 0);
  var V = v.V;
  Z f(a);
  unique(f);
  for (int &x : a) x = lb(f, x);
  sswave wm(rearrange(a, V));
  FOR(i, N) {
    int l = v.L[i], r = v.R[i];
    print(wm.count(l, r, a[i] + 1, si(f)));
  }
}

int main() {
  Yorisou();
  return 0;
}