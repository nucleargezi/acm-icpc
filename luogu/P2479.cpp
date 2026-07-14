#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/kdt/kdt_man.hpp"

void Yorisou() {
  INT(N);
  vc<T3<int>> dat(N);
  FOR(i, N) {
    Z &[x, y, id] = dat[i];
    IN(x, y);
    id = i;
  }
  kdt_man ds(all(dat));
  ll s = inf<int>;
  for (var [x, y, i] : dat) {
    chmin(s, ds.farest(x, y, i).fi - ds.nearest(x, y, i).fi);
  }
  print(s);
}

int main() {
  Yorisou();
  return 0;
}