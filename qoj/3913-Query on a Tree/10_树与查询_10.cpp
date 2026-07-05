#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/al/am/max_subarray_sum_set.hpp"
#include "YRS/ttr/hld_sayo.hpp"

using sayo = Max_subarr_sum_set<ll>;
void Yorisou() {
  INT(N);
  vc<sayo::X> dat(N);
  FOR(i, N) {
    INT(x);
    dat[i] = sayo::sing(x);
  }
  vc<vc<int>> g(N);
  FOR(N - 1) {
    INT(a, b);
    --a, --b;
    g[a].ep(b), g[b].ep(a);
  }
  hld v(g, 0);
  hld_sayo<int, sayo> seg(v, dat);

  INT(Q);
  FOR(Q) {
    INT(op, a, b);
    --a, --b;
    if (op == 1) {
      print(seg.prod(a, b).mx);
    } else {
      INT(x);
      seg.apply(a, b, x);
    }
  }
}

int main() {
  Yorisou();
  return 0;
}