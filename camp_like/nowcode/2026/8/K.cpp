#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/flow/mcf_dag.hpp"

void Yorisou() {
  INT(N, a, b, K);
  int s = 0, t = a + b + 1;
  mcf_dag<int, ll> g(t + 1);

  FOR(i, 1, a + 1) {
    INT(f, c);
    if (f == 0) {
      g.add(s, i, min(c, K), 0);
    } else {
      g.add(f, i, c, 0);
    }
  }
  
  FOR(i, b) {
    INT(f, c);
    if (f == 0) {
      g.add(a + b - i, t, min(c, K), 0);
    } else {
      --f;
      g.add(a + b - i, a + b - f, c, 0);
    }
  }

  FOR(N) {
    INT(l, r, w);
    --r;
    g.add(l, a + b - r, 1, -w);
  }

  Z [F, C] = g.flow(s, t);
  if (F != K) print(-1);
  else print(-C);
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}