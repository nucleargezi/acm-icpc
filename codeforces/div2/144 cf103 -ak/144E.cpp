#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N, M);
  vc<T3<int>> dat;
  FOR(i, M) {
    INT(x, y);
    dat.ep(x, N - y, i);
  }
  set<int> se;
  FOR(i, N) se.eb(i);
  vc<int> rs;
  sort(dat);
  for (var [r, l, i] : dat) {
    Z it = se.lower_bound(l);
    if (it == ed(se)) continue;
    if (*it < r) rs.ep(i + 1), se.erase(it);
  }
  print(si(rs));
  print(rs);
}

int main() {
  Yorisou();
  return 0;
}