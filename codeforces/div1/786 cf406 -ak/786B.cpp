#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/gg/range_g.hpp"

void Yorisou() {
  INT(N, M, s);
  --s;
  range_g<int> g(N);
  FOR(M) {
    INT(op);
    if (op == 1) {
      INT(f, t, w);
      --f, --t;
      g.add(f, f + 1, t, t + 1, w);
    } else if (op == 2) {
      INT(f, l, r, w);
      --f, --l;
      g.add(f, f + 1, l, r, w);
    } else {
      INT(t, l, r, w);
      --l, --t;
      g.add(l, r, t, t + 1, w);
    }
  }
  Z dis = g.dij<ll>(s);
  FOR(i, N) if (dis[i] == inf<ll>) dis[i] = -1;
  print(dis);
}

int main() {
  Yorisou();
  return 0;
}