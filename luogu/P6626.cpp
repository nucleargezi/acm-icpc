#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
#include "YRS/tr/near_kinbo.hpp"

void Yorisou() {
  INT(N, Q);
  graph g(N);
  g.sc();
  near_kinbo ds(g);
  vc<int> dat(ds.tt);
  FOR(i, N) for (int x : ds.vs(i)) ++dat[x];
  dat = pre_sum(dat);
  FOR(Q) {
    INT(x, k);
    --x;
    int s = 0;
    for (Z [l, r] : ds.range(x, k, k + 1)) s += dat[r] - dat[l];
    print(s);
  }
}
constexpr int tests = 1, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"